#pragma once

#include <mbgl/gl/gl_types.hpp>

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