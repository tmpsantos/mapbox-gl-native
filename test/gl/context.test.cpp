#include <mbgl/test/util.hpp>

#include <mbgl/gl/gl.hpp>
#include <mbgl/gl/context.hpp>
#include <mbgl/map/map.hpp>
#include <mbgl/util/default_thread_pool.hpp>
#include <mbgl/storage/default_file_source.hpp>
#include <mbgl/gl/headless_frontend.hpp>
#include <mbgl/style/style.hpp>
#include <mbgl/style/layers/custom_layer.hpp>
#include <mbgl/style/layers/fill_layer.hpp>
#include <mbgl/style/layers/background_layer.hpp>
#include <mbgl/util/io.hpp>
#include <mbgl/util/mat4.hpp>
#include <mbgl/util/run_loop.hpp>

using namespace mbgl;
using namespace mbgl::style;

static const GLchar* vertexShaderSource = R"MBGL_SHADER(
#ifdef GL_ES
precision mediump float;
#endif
attribute vec2 a_pos;
void main() {
    gl_Position = vec4(a_pos, 0, 1);
}
)MBGL_SHADER";

static const GLchar* fragmentShaderSource = R"MBGL_SHADER(
#ifdef GL_ES
precision mediump float;
#endif
void main() {
    gl_FragColor = vec4(0, 1, 0, 1);
}
)MBGL_SHADER";

struct Shader {
    Shader(const GLchar* vertex, const GLchar* fragment) {
        program = mbgl::gl::getGLFunctionPointers().glCreateProgram();
        vertexShader = mbgl::gl::getGLFunctionPointers().glCreateShader(GL_VERTEX_SHADER);
        fragmentShader = mbgl::gl::getGLFunctionPointers().glCreateShader(GL_FRAGMENT_SHADER);
        mbgl::gl::getGLFunctionPointers().glShaderSource(vertexShader, 1, &vertex, nullptr);
        mbgl::gl::getGLFunctionPointers().glCompileShader(vertexShader);
        mbgl::gl::getGLFunctionPointers().glAttachShader(program, vertexShader);
        mbgl::gl::getGLFunctionPointers().glShaderSource(fragmentShader, 1, &fragment, nullptr);
        mbgl::gl::getGLFunctionPointers().glCompileShader(fragmentShader);
        mbgl::gl::getGLFunctionPointers().glAttachShader(program, fragmentShader);
        mbgl::gl::getGLFunctionPointers().glLinkProgram(program);
        a_pos = mbgl::gl::getGLFunctionPointers().glGetAttribLocation(program, "a_pos");
    }

    ~Shader() {
        mbgl::gl::getGLFunctionPointers().glDetachShader(program, vertexShader);
        mbgl::gl::getGLFunctionPointers().glDetachShader(program, fragmentShader);
        mbgl::gl::getGLFunctionPointers().glDeleteShader(vertexShader);
        mbgl::gl::getGLFunctionPointers().glDeleteShader(fragmentShader);
        mbgl::gl::getGLFunctionPointers().glDeleteProgram(program);
    }

    GLuint program = 0;
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    GLuint a_pos = 0;
};

struct Buffer {
    Buffer(std::vector<GLfloat> data) {
        mbgl::gl::getGLFunctionPointers().glGenBuffers(1, &buffer);
        mbgl::gl::getGLFunctionPointers().glBindBuffer(GL_ARRAY_BUFFER, buffer);
        mbgl::gl::getGLFunctionPointers().glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(),
                                      GL_STATIC_DRAW);
    }

    ~Buffer() {
        mbgl::gl::getGLFunctionPointers().glDeleteBuffers(1, &buffer);
    }

    GLuint buffer = 0;
};

TEST(GLContextMode, Shared) {
    util::RunLoop loop;

    DefaultFileSource fileSource(":memory:", "test/fixtures/api/assets");
    ThreadPool threadPool(4);
    float pixelRatio { 1 };

    HeadlessFrontend frontend { pixelRatio, fileSource, threadPool, {}, GLContextMode::Shared };

    Map map(frontend, MapObserver::nullObserver(), frontend.getSize(), pixelRatio, fileSource, threadPool, MapMode::Static);
    map.getStyle().loadJSON(util::read_file("test/fixtures/api/water.json"));
    map.setLatLngZoom({ 37.8, -122.5 }, 10);

    // Set transparent background layer.
    auto layer = map.getStyle().getLayer("background");
    ASSERT_STREQ("background", layer->getTypeInfo()->type);
    static_cast<BackgroundLayer*>(layer)->setBackgroundColor( { { 1.0f, 0.0f, 0.0f, 0.5f } } );

    {
        // Custom rendering outside of GL Native render loop.
        BackendScope scope { *frontend.getBackend() };
        frontend.getBackend()->bind();

        Shader paintShader(vertexShaderSource, fragmentShaderSource);
        Buffer triangleBuffer({ 0, 0.5, 0.5, -0.5, -0.5, -0.5 });
        mbgl::gl::getGLFunctionPointers().glUseProgram(paintShader.program);
        mbgl::gl::getGLFunctionPointers().glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer.buffer);
        mbgl::gl::getGLFunctionPointers().glEnableVertexAttribArray(paintShader.a_pos);
        mbgl::gl::getGLFunctionPointers().glVertexAttribPointer(paintShader.a_pos, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        mbgl::gl::getGLFunctionPointers().glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    }

    test::checkImage("test/fixtures/shared_context", frontend.render(map), 0.5, 0.1);
}
