#include <mbgl/test/util.hpp>

#include <mbgl/gl/gl.hpp>
#include <mbgl/gl/context.hpp>
#include <mbgl/gl/headless_backend.hpp>
#include <mbgl/renderer/backend_scope.hpp>

#include <mbgl/util/offscreen_texture.hpp>

using namespace mbgl;

TEST(OffscreenTexture, EmptyRed) {
    HeadlessBackend backend({ 512, 256 });
    BackendScope scope { backend };

    // Scissor test shouldn't leak after HeadlessBackend::bind().
    mbgl::gl::getGLFunctionPointers().glScissor(64, 64, 128, 128);
    backend.getContext().scissorTest.setCurrentValue(true);

    backend.bind();

    mbgl::gl::getGLFunctionPointers().glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    mbgl::gl::getGLFunctionPointers().glClear(GL_COLOR_BUFFER_BIT);

    auto image = backend.readStillImage();
    test::checkImage("test/fixtures/offscreen_texture/empty-red", image, 0, 0);
}

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


TEST(OffscreenTexture, RenderToTexture) {
    HeadlessBackend backend({ 512, 256 });
    BackendScope scope { backend };
    auto& context = backend.getContext();

    mbgl::gl::getGLFunctionPointers().glEnable(GL_BLEND);
    mbgl::gl::getGLFunctionPointers().glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Shader paintShader(R"MBGL_SHADER(
#ifdef GL_ES
precision mediump float;
#endif
attribute vec2 a_pos;
void main() {
    gl_Position = vec4(a_pos, 0, 1);
}
)MBGL_SHADER", R"MBGL_SHADER(
#ifdef GL_ES
precision mediump float;
#endif
void main() {
    gl_FragColor = vec4(0, 0.8, 0, 0.8);
}
)MBGL_SHADER");

        Shader compositeShader(R"MBGL_SHADER(
#ifdef GL_ES
precision mediump float;
#endif
attribute vec2 a_pos;
varying vec2 v_texcoord;
void main() {
    gl_Position = vec4(a_pos, 0, 1);
    v_texcoord = (a_pos + 1.0) / 2.0;
}
)MBGL_SHADER", R"MBGL_SHADER(
#ifdef GL_ES
precision mediump float;
#endif
uniform sampler2D u_texture;
varying vec2 v_texcoord;
void main() {
    gl_FragColor = texture2D(u_texture, v_texcoord);
}
)MBGL_SHADER");

    GLuint u_texture = mbgl::gl::getGLFunctionPointers().glGetUniformLocation(compositeShader.program, "u_texture");

    Buffer triangleBuffer({ 0, 0.5, 0.5, -0.5, -0.5, -0.5 });
    Buffer viewportBuffer({ -1, -1, 1, -1, -1, 1, 1, 1 });

    backend.bind();

    // First, draw red to the bound FBO.
    context.clear(Color::red(), {}, {});

    // Then, create a texture, bind it, and render yellow to that texture. This should not
    // affect the originally bound FBO.
    OffscreenTexture texture(context, { 128, 128 });

    // Scissor test shouldn't leak after OffscreenTexture::bind().
    mbgl::gl::getGLFunctionPointers().glScissor(32, 32, 64, 64);
    context.scissorTest.setCurrentValue(true);

    texture.bind();

    context.clear(Color(), {}, {});

    mbgl::gl::getGLFunctionPointers().glUseProgram(paintShader.program);
    mbgl::gl::getGLFunctionPointers().glBindBuffer(GL_ARRAY_BUFFER, triangleBuffer.buffer);
    mbgl::gl::getGLFunctionPointers().glEnableVertexAttribArray(paintShader.a_pos);
    mbgl::gl::getGLFunctionPointers().
        glVertexAttribPointer(paintShader.a_pos, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    mbgl::gl::getGLFunctionPointers().glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);

    auto image = texture.readStillImage();
    test::checkImage("test/fixtures/offscreen_texture/render-to-texture", image, 0, 0);

    // Now reset the FBO back to normal and retrieve the original (restored) framebuffer.
    backend.bind();

    image = backend.readStillImage();
    test::checkImage("test/fixtures/offscreen_texture/render-to-fbo", image, 0, 0);

    // Now, composite the Framebuffer texture we've rendered to onto the main FBO.
    context.bindTexture(texture.getTexture(), 0, gl::TextureFilter::Linear);
    mbgl::gl::getGLFunctionPointers().glUseProgram(compositeShader.program);
    mbgl::gl::getGLFunctionPointers().glUniform1i(u_texture, 0);
    mbgl::gl::getGLFunctionPointers().glBindBuffer(GL_ARRAY_BUFFER, viewportBuffer.buffer);
    mbgl::gl::getGLFunctionPointers().glEnableVertexAttribArray(compositeShader.a_pos);
    mbgl::gl::getGLFunctionPointers().
        glVertexAttribPointer(compositeShader.a_pos, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    mbgl::gl::getGLFunctionPointers().glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    image = backend.readStillImage();
    test::checkImage("test/fixtures/offscreen_texture/render-to-fbo-composited", image, 0, 0.1);
}
