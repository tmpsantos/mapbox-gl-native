#pragma once

#include <cstddef>

using GLbitfield = unsigned int;
using GLboolean = unsigned char;
using GLchar = char;
using GLdouble = double;
using GLenum = unsigned int;
using GLfloat = float;
using GLint = int;
using GLsizei = int;
using GLubyte = unsigned char;
using GLuint = unsigned int;
using GLvoid = void;

#if defined(_WINDOWS)
using GLintptr = long long;
using GLsizeiptr = long long;
#else
using GLintptr = long;
using GLsizeiptr = long;
#endif

#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ALPHA 0x1906
#define GL_ALWAYS 0x0207
#define GL_ARRAY_BUFFER 0x8892
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_BACK 0x0405
#define GL_BLEND 0x0BE2
#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_BYTE 0x1400
#define GL_CCW 0x0901
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_COMPILE_STATUS 0x8B81
#define GL_CONSTANT_ALPHA 0x8003
#define GL_CONSTANT_COLOR 0x8001
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_CW 0x0900
#define GL_DECR 0x1E03
#define GL_DECR_WRAP 0x8508
#define GL_DEPTH24_STENCIL8_OES 0x88F0
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_FUNC 0x0B74
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DONT_CARE 0x1100
#define GL_DST_ALPHA 0x0304
#define GL_DST_COLOR 0x0306
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_EQUAL 0x0202
#define GL_EXTENSIONS 0x1F03
#define GL_FALSE 0
#define GL_FLOAT 0x1406
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_FRAMEBUFFER 0x8D40
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_FRONT 0x0404
#define GL_FRONT_AND_BACK 0x0408
#define GL_FRONT_FACE 0x0B46
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_GEQUAL 0x0206
#define GL_GREATER 0x0204
#define GL_INCR 0x1E02
#define GL_INCR_WRAP 0x8507
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_INT 0x1404
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_INVALID_OPERATION 0x0502
#define GL_INVALID_VALUE 0x0501
#define GL_INVERT 0x150A
#define GL_KEEP 0x1E00
#define GL_LEQUAL 0x0203
#define GL_LESS 0x0201
#define GL_LINEAR 0x2601
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_LINE_LOOP 0x0002
#define GL_LINES 0x0001
#define GL_LINE_STRIP 0x0003
#define GL_LINE_WIDTH 0x0B21
#define GL_LINK_STATUS 0x8B82
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_NEAREST 0x2600
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_NEVER 0x0200
#define GL_NO_ERROR 0
#define GL_NOTEQUAL 0x0205
#define GL_ONE 1
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_OUT_OF_MEMORY 0x0505
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_POINTS 0x0000
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_RENDERER 0x1F01
#define GL_REPEAT 0x2901
#define GL_REPLACE 0x1E01
#define GL_RGBA 0x1908
#define GL_RGBA8_OES 0x8058
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SCISSOR_TEST 0x0C11
#define GL_SHORT 0x1402
#define GL_SRC_ALPHA 0x0302
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_SRC_COLOR 0x0300
#define GL_STATIC_DRAW 0x88E4
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_STREAM_DRAW 0x88E0
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_TRIANGLE_FAN 0x0006
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRUE 1
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT 0x1405
#define GL_UNSIGNED_SHORT 0x1403
#define GL_VERTEX_SHADER 0x8B31
#define GL_VIEWPORT 0x0BA2
#define GL_ZERO 0

namespace mbgl {
namespace gl {

/**
 * @brief Holds pointers to OpenGL ES 2.0 functions. Loading these
 * functions should be done by the platform, before doing any GL
 * operation. The initialization hook is called when creating the
 * GL context.
 */
struct GLFunctions {
public:
    static void (*glActiveTexture)(GLenum);
    static void (*glAttachShader)(GLuint, GLuint);
    static void (*glBindAttribLocation)(GLuint, GLuint, const GLchar *);
    static void (*glBindBuffer)(GLenum, GLuint);
    static void (*glBindFramebuffer)(GLenum, GLuint);
    static void (*glBindRenderbuffer)(GLenum, GLuint);
    static void (*glBindTexture)(GLenum, GLuint);
    static void (*glBlendColor)(GLfloat, GLfloat, GLfloat, GLfloat);
    static void (*glBlendEquation)(GLenum);
    static void (*glBlendEquationSeparate)(GLenum, GLenum);
    static void (*glBlendFunc)(GLenum, GLenum);
    static void (*glBlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum);
    static void (*glBufferData)(GLenum, GLsizeiptr, const void *, GLenum);
    static void (*glBufferSubData)(GLenum, GLintptr, GLsizeiptr, const void *);
    static GLenum (*glCheckFramebufferStatus)(GLenum);
    static void (*glClear)(GLbitfield);
    static void (*glClearColor)(GLfloat, GLfloat, GLfloat, GLfloat);
    static void (*glClearDepthf)(GLfloat);
    static void (*glClearStencil)(GLint);
    static void (*glColorMask)(GLboolean, GLboolean, GLboolean, GLboolean);
    static void (*glCompileShader)(GLuint);
    static void (*glCompressedTexImage2D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *);
    static void (*glCompressedTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *);
    static void (*glCopyTexImage2D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
    static void (*glCopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
    static GLuint (*glCreateProgram)();
    static GLuint (*glCreateShader)(GLenum);
    static void (*glCullFace)(GLenum);
    static void (*glDeleteBuffers)(GLsizei, const GLuint *);
    static void (*glDeleteFramebuffers)(GLsizei, const GLuint *);
    static void (*glDeleteProgram)(GLuint);
    static void (*glDeleteRenderbuffers)(GLsizei, const GLuint *);
    static void (*glDeleteShader)(GLuint);
    static void (*glDeleteTextures)(GLsizei, const GLuint *);
    static void (*glDepthFunc)(GLenum);
    static void (*glDepthMask)(GLboolean);
    static void (*glDepthRangef)(GLfloat, GLfloat);
    static void (*glDetachShader)(GLuint, GLuint);
    static void (*glDisable)(GLenum);
    static void (*glDisableVertexAttribArray)(GLuint);
    static void (*glDrawArrays)(GLenum, GLint, GLsizei);
    static void (*glDrawElements)(GLenum, GLsizei, GLenum, const void *);
    static void (*glEnable)(GLenum);
    static void (*glEnableVertexAttribArray)(GLuint);
    static void (*glFinish)();
    static void (*glFlush)();
    static void (*glFramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint);
    static void (*glFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint);
    static void (*glFrontFace)(GLenum);
    static void (*glGenBuffers)(GLsizei, GLuint *);
    static void (*glGenerateMipmap)(GLenum);
    static void (*glGenFramebuffers)(GLsizei, GLuint *);
    static void (*glGenRenderbuffers)(GLsizei, GLuint *);
    static void (*glGenTextures)(GLsizei, GLuint *);
    static void (*glGetActiveAttrib)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
    static void (*glGetActiveUniform)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
    static void (*glGetAttachedShaders)(GLuint, GLsizei, GLsizei *, GLuint *);
    static GLint (*glGetAttribLocation)(GLuint, const GLchar *);
    static void (*glGetBooleanv)(GLenum, GLboolean *);
    static void (*glGetBufferParameteriv)(GLenum, GLenum, GLint *);
    static GLenum (*glGetError)();
    static void (*glGetFloatv)(GLenum, GLfloat *);
    static void (*glGetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *);
    static void (*glGetIntegerv)(GLenum, GLint *);
    static void (*glGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
    static void (*glGetProgramiv)(GLuint, GLenum, GLint *);
    static void (*glGetRenderbufferParameteriv)(GLenum, GLenum, GLint *);
    static void (*glGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
    static void (*glGetShaderiv)(GLuint, GLenum, GLint *);
    static void (*glGetShaderSource)(GLuint, GLsizei, GLsizei *, GLchar *);
    static const GLubyte *(*glGetString)(GLenum);
    static void (*glGetTexParameterfv)(GLenum, GLenum, GLfloat *);
    static void (*glGetTexParameteriv)(GLenum, GLenum, GLint *);
    static void (*glGetUniformfv)(GLuint, GLint, GLfloat *);
    static void (*glGetUniformiv)(GLuint, GLint, GLint *);
    static GLint (*glGetUniformLocation)(GLuint, const GLchar *);
    static void (*glGetVertexAttribfv)(GLuint, GLenum, GLfloat *);
    static void (*glGetVertexAttribiv)(GLuint, GLenum, GLint *);
    static void (*glGetVertexAttribPointerv)(GLuint, GLenum, void **);
    static void (*glHint)(GLenum, GLenum);
    static GLboolean (*glIsBuffer)(GLuint);
    static GLboolean (*glIsEnabled)(GLenum);
    static GLboolean (*glIsFramebuffer)(GLuint);
    static GLboolean (*glIsProgram)(GLuint);
    static GLboolean (*glIsRenderbuffer)(GLuint);
    static GLboolean (*glIsShader)(GLuint);
    static GLboolean (*glIsTexture)(GLuint);
    static void (*glLineWidth)(GLfloat);
    static void (*glLinkProgram)(GLuint);
    static void (*glPixelStorei)(GLenum, GLint);
    static void (*glPolygonOffset)(GLfloat, GLfloat);
    static void (*glReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *);
    static void (*glRenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei);
    static void (*glSampleCoverage)(GLfloat, GLboolean);
    static void (*glScissor)(GLint, GLint, GLsizei, GLsizei);
    static void (*glShaderSource)(GLuint, GLsizei, const GLchar * const*, const GLint *);
    static void (*glStencilFunc)(GLenum, GLint, GLuint);
    static void (*glStencilFuncSeparate)(GLenum, GLenum, GLint, GLuint);
    static void (*glStencilMask)(GLuint);
    static void (*glStencilMaskSeparate)(GLenum, GLuint);
    static void (*glStencilOp)(GLenum, GLenum, GLenum);
    static void (*glStencilOpSeparate)(GLenum, GLenum, GLenum, GLenum);
    static void (*glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *);
    static void (*glTexParameterf)(GLenum, GLenum, GLfloat);
    static void (*glTexParameterfv)(GLenum, GLenum, const GLfloat *);
    static void (*glTexParameteri)(GLenum, GLenum, GLint);
    static void (*glTexParameteriv)(GLenum, GLenum, const GLint *);
    static void (*glTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
    static void (*glUniform1f)(GLint, GLfloat);
    static void (*glUniform1fv)(GLint, GLsizei, const GLfloat *);
    static void (*glUniform1i)(GLint, GLint);
    static void (*glUniform1iv)(GLint, GLsizei, const GLint *);
    static void (*glUniform2f)(GLint, GLfloat, GLfloat);
    static void (*glUniform2fv)(GLint, GLsizei, const GLfloat *);
    static void (*glUniform2i)(GLint, GLint, GLint);
    static void (*glUniform2iv)(GLint, GLsizei, const GLint *);
    static void (*glUniform3f)(GLint, GLfloat, GLfloat, GLfloat);
    static void (*glUniform3fv)(GLint, GLsizei, const GLfloat *);
    static void (*glUniform3i)(GLint, GLint, GLint, GLint);
    static void (*glUniform3iv)(GLint, GLsizei, const GLint *);
    static void (*glUniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
    static void (*glUniform4fv)(GLint, GLsizei, const GLfloat *);
    static void (*glUniform4i)(GLint, GLint, GLint, GLint, GLint);
    static void (*glUniform4iv)(GLint, GLsizei, const GLint *);
    static void (*glUniformMatrix2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
    static void (*glUniformMatrix3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
    static void (*glUniformMatrix4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
    static void (*glUseProgram)(GLuint);
    static void (*glValidateProgram)(GLuint);
    static void (*glVertexAttrib1f)(GLuint, GLfloat);
    static void (*glVertexAttrib1fv)(GLuint, const GLfloat *);
    static void (*glVertexAttrib2f)(GLuint, GLfloat, GLfloat);
    static void (*glVertexAttrib2fv)(GLuint, const GLfloat *);
    static void (*glVertexAttrib3f)(GLuint, GLfloat, GLfloat, GLfloat);
    static void (*glVertexAttrib3fv)(GLuint, const GLfloat *);
    static void (*glVertexAttrib4f)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
    static void (*glVertexAttrib4fv)(GLuint, const GLfloat *);
    static void (*glVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *);
    static void (*glViewport)(GLint, GLint, GLsizei, GLsizei);

protected:
    GLFunctions() = default;
};

}  // namespace gl
}  // namespace mbgl