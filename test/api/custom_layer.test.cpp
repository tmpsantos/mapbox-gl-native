#include <mbgl/test/util.hpp>

#include <mbgl/gl/gl.hpp>
#include <mbgl/map/map.hpp>
#include <mbgl/util/default_thread_pool.hpp>
#include <mbgl/storage/default_file_source.hpp>
#include <mbgl/gl/headless_frontend.hpp>
#include <mbgl/style/style.hpp>
#include <mbgl/style/layers/custom_layer.hpp>
#include <mbgl/style/layers/fill_layer.hpp>
#include <mbgl/util/io.hpp>
#include <mbgl/util/mat4.hpp>
#include <mbgl/util/run_loop.hpp>

using namespace mbgl;
using namespace mbgl::style;

// Note that custom layers need to draw geometry with a z value of 1 to take advantage of
// depth-based fragment culling.
static const GLchar* vertexShaderSource = R"MBGL_SHADER(
attribute vec2 a_pos;
void main() {
    gl_Position = vec4(a_pos, 1, 1);
}
)MBGL_SHADER";

static const GLchar* fragmentShaderSource = R"MBGL_SHADER(
void main() {
    gl_FragColor = vec4(0, 0.5, 0, 0.5);
}
)MBGL_SHADER";

// Not using any mbgl-specific stuff (other than a basic error-checking macro) in the
// layer implementation because it is intended to reflect how someone using custom layers
// might actually write their own implementation.

class TestLayer : public mbgl::style::CustomLayerHost {
public:
    void initialize() {
        program = mbgl::gl::getGLFunctionPointers().glCreateProgram();
        vertexShader = mbgl::gl::getGLFunctionPointers().glCreateShader(GL_VERTEX_SHADER);
        fragmentShader = mbgl::gl::getGLFunctionPointers().glCreateShader(GL_FRAGMENT_SHADER);

        mbgl::gl::getGLFunctionPointers().glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        mbgl::gl::getGLFunctionPointers().glCompileShader(vertexShader);
        mbgl::gl::getGLFunctionPointers().glAttachShader(program, vertexShader);
        mbgl::gl::getGLFunctionPointers().glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        mbgl::gl::getGLFunctionPointers().glCompileShader(fragmentShader);
        mbgl::gl::getGLFunctionPointers().glAttachShader(program, fragmentShader);
        mbgl::gl::getGLFunctionPointers().glLinkProgram(program);
        a_pos = mbgl::gl::getGLFunctionPointers().glGetAttribLocation(program, "a_pos");

        GLfloat triangle[] = { 0, 0.5, 0.5, -0.5, -0.5, -0.5 };
        mbgl::gl::getGLFunctionPointers().glGenBuffers(1, &buffer);
        mbgl::gl::getGLFunctionPointers().glBindBuffer(GL_ARRAY_BUFFER, buffer);
        mbgl::gl::getGLFunctionPointers().glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), triangle, GL_STATIC_DRAW);
    }

    void render(const mbgl::style::CustomLayerRenderParameters&) {
        mbgl::gl::getGLFunctionPointers().glUseProgram(program);
        mbgl::gl::getGLFunctionPointers().glBindBuffer(GL_ARRAY_BUFFER, buffer);
        mbgl::gl::getGLFunctionPointers().glEnableVertexAttribArray(a_pos);
        mbgl::gl::getGLFunctionPointers().glVertexAttribPointer(a_pos, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        mbgl::gl::getGLFunctionPointers().glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    }

    void contextLost() {}

    void deinitialize() {
         if (program) {
                mbgl::gl::getGLFunctionPointers().glDeleteBuffers(1, &buffer);
                mbgl::gl::getGLFunctionPointers().glDetachShader(program, vertexShader);
                mbgl::gl::getGLFunctionPointers().glDetachShader(program, fragmentShader);
                mbgl::gl::getGLFunctionPointers().glDeleteShader(vertexShader);
                mbgl::gl::getGLFunctionPointers().glDeleteShader(fragmentShader);
                mbgl::gl::getGLFunctionPointers().glDeleteProgram(program);
            }
    }

    GLuint program = 0;
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    GLuint buffer = 0;
    GLuint a_pos = 0;
};

TEST(CustomLayer, Basic) {
    util::RunLoop loop;

    DefaultFileSource fileSource(":memory:", "test/fixtures/api/assets");
    ThreadPool threadPool(4);
    float pixelRatio { 1 };
    HeadlessFrontend frontend { pixelRatio, fileSource, threadPool };
    Map map(frontend, MapObserver::nullObserver(), frontend.getSize(), pixelRatio, fileSource,
            threadPool, MapMode::Static);
    map.getStyle().loadJSON(util::read_file("test/fixtures/api/water.json"));
    map.setLatLngZoom({ 37.8, -122.5 }, 10);
    map.getStyle().addLayer(std::make_unique<CustomLayer>(
        "custom",
        std::make_unique<TestLayer>()));

    auto layer = std::make_unique<FillLayer>("landcover", "mapbox");
    layer->setSourceLayer("landcover");
    layer->setFillColor(Color{ 1.0, 1.0, 0.0, 1.0 });
    map.getStyle().addLayer(std::move(layer));

    test::checkImage("test/fixtures/custom_layer/basic", frontend.render(map), 0.0006, 0.1);
}
