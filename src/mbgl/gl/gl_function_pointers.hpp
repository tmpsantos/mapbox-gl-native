#pragma once

#include <mbgl/gl/gl_types.hpp>

namespace mbgl {
namespace gl {

/**
 * @brief Holds pointers to OpenGL functions.
 */
struct GLFunctionPointers {
    /// Pointer to glActiveTexture OpenGL function.
    void (*glActiveTexture)(GLenum);
    /// Pointer to glAttachShader OpenGL function.
    void (*glAttachShader)(GLuint, GLuint);
    /// Pointer to glBindAttribLocation OpenGL function.
    void (*glBindAttribLocation)(GLuint, GLuint, const GLchar *);
    /// Pointer to glBindBuffer OpenGL function.
    void (*glBindBuffer)(GLenum, GLuint);
    /// Pointer to glBindFramebuffer OpenGL function.
    void (*glBindFramebuffer)(GLenum, GLuint);
    /// Pointer to glBindRenderbuffer OpenGL function.
    void (*glBindRenderbuffer)(GLenum, GLuint);
    /// Pointer to glBindTexture OpenGL function.
    void (*glBindTexture)(GLenum, GLuint);
    /// Pointer to glBlendColor OpenGL function.
    void (*glBlendColor)(GLfloat, GLfloat, GLfloat, GLfloat);
    /// Pointer to glBlendEquation OpenGL function.
    void (*glBlendEquation)(GLenum);
    /// Pointer to glBlendEquationSeparate OpenGL function.
    void (*glBlendEquationSeparate)(GLenum, GLenum);
    /// Pointer to glBlendFunc OpenGL function.
    void (*glBlendFunc)(GLenum, GLenum);
    /// Pointer to glBlendFuncSeparate OpenGL function.
    void (*glBlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum);
    /// Pointer to glBufferData OpenGL function.
    void (*glBufferData)(GLenum, GLsizeiptr, const void *, GLenum);
    /// Pointer to glBufferSubData OpenGL function.
    void (*glBufferSubData)(GLenum, GLintptr, GLsizeiptr, const void *);
    /// Pointer to glCheckFramebufferStatus OpenGL function.
    GLenum (*glCheckFramebufferStatus)(GLenum);
    /// Pointer to glClear OpenGL function.
    void (*glClear)(GLbitfield);
    /// Pointer to glClearColor OpenGL function.
    void (*glClearColor)(GLfloat, GLfloat, GLfloat, GLfloat);
    /// Pointer to glClearDepthf OpenGL function.
    void (*glClearDepthf)(GLfloat);
    /// Pointer to glClearStencil OpenGL function.
    void (*glClearStencil)(GLint);
    /// Pointer to glColorMask OpenGL function.
    void (*glColorMask)(GLboolean, GLboolean, GLboolean, GLboolean);
    /// Pointer to glCompileShader OpenGL function.
    void (*glCompileShader)(GLuint);
    /// Pointer to glCompressedTexImage2D OpenGL function.
    void (*glCompressedTexImage2D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *);
    /// Pointer to glCompressedTexSubImage2D OpenGL function.
    void (*glCompressedTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *);
    /// Pointer to glCopyTexImage2D OpenGL function.
    void (*glCopyTexImage2D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
    /// Pointer to glCopyTexSubImage2D OpenGL function.
    void (*glCopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
    /// Pointer to glCreateProgram OpenGL function.
    GLuint (*glCreateProgram)();
    /// Pointer to glCreateShader OpenGL function.
    GLuint (*glCreateShader)(GLenum);
    /// Pointer to glCullFace OpenGL function.
    void (*glCullFace)(GLenum);
    /// Pointer to glDeleteBuffers OpenGL function.
    void (*glDeleteBuffers)(GLsizei, const GLuint *);
    /// Pointer to glDeleteFramebuffers OpenGL function.
    void (*glDeleteFramebuffers)(GLsizei, const GLuint *);
    /// Pointer to glDeleteProgram OpenGL function.
    void (*glDeleteProgram)(GLuint);
    /// Pointer to glDeleteRenderbuffers OpenGL function.
    void (*glDeleteRenderbuffers)(GLsizei, const GLuint *);
    /// Pointer to glDeleteShader OpenGL function.
    void (*glDeleteShader)(GLuint);
    /// Pointer to glDeleteTextures OpenGL function.
    void (*glDeleteTextures)(GLsizei, const GLuint *);
    /// Pointer to glDepthFunc OpenGL function.
    void (*glDepthFunc)(GLenum);
    /// Pointer to glDepthMask OpenGL function.
    void (*glDepthMask)(GLboolean);
    /// Pointer to glDepthRangef OpenGL function.
    void (*glDepthRangef)(GLfloat, GLfloat);
    /// Pointer to glDetachShader OpenGL function.
    void (*glDetachShader)(GLuint, GLuint);
    /// Pointer to glDisable OpenGL function.
    void (*glDisable)(GLenum);
    /// Pointer to glDisableVertexAttribArray OpenGL function.
    void (*glDisableVertexAttribArray)(GLuint);
    /// Pointer to glDrawArrays OpenGL function.
    void (*glDrawArrays)(GLenum, GLint, GLsizei);
    /// Pointer to glDrawElements OpenGL function.
    void (*glDrawElements)(GLenum, GLsizei, GLenum, const void *);
    /// Pointer to glEnable OpenGL function.
    void (*glEnable)(GLenum);
    /// Pointer to glEnableVertexAttribArray OpenGL function.
    void (*glEnableVertexAttribArray)(GLuint);
    /// Pointer to glFinish OpenGL function.
    void (*glFinish)();
    /// Pointer to glFlush OpenGL function.
    void (*glFlush)();
    /// Pointer to glFramebufferRenderbuffer OpenGL function.
    void (*glFramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint);
    /// Pointer to glFramebufferTexture2D OpenGL function.
    void (*glFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint);
    /// Pointer to glFrontFace OpenGL function.
    void (*glFrontFace)(GLenum);
    /// Pointer to glGenBuffers OpenGL function.
    void (*glGenBuffers)(GLsizei, GLuint *);
    /// Pointer to glGenerateMipmap OpenGL function.
    void (*glGenerateMipmap)(GLenum);
    /// Pointer to glGenFramebuffers OpenGL function.
    void (*glGenFramebuffers)(GLsizei, GLuint *);
    /// Pointer to glGenRenderbuffers OpenGL function.
    void (*glGenRenderbuffers)(GLsizei, GLuint *);
    /// Pointer to glGenTextures OpenGL function.
    void (*glGenTextures)(GLsizei, GLuint *);
    /// Pointer to glGetActiveAttrib OpenGL function.
    void (*glGetActiveAttrib)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
    /// Pointer to glGetActiveUniform OpenGL function.
    void (*glGetActiveUniform)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
    /// Pointer to glGetAttachedShaders OpenGL function.
    void (*glGetAttachedShaders)(GLuint, GLsizei, GLsizei *, GLuint *);
    /// Pointer to glGetAttribLocation OpenGL function.
    GLint (*glGetAttribLocation)(GLuint, const GLchar *);
    /// Pointer to glGetBooleanv OpenGL function.
    void (*glGetBooleanv)(GLenum, GLboolean *);
    /// Pointer to glGetBufferParameteriv OpenGL function.
    void (*glGetBufferParameteriv)(GLenum, GLenum, GLint *);
    /// Pointer to glGetError OpenGL function.
    GLenum (*glGetError)();
    /// Pointer to glGetFloatv OpenGL function.
    void (*glGetFloatv)(GLenum, GLfloat *);
    /// Pointer to glGetFramebufferAttachmentParameteriv OpenGL function.
    void (*glGetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *);
    /// Pointer to glGetIntegerv OpenGL function.
    void (*glGetIntegerv)(GLenum, GLint *);
    /// Pointer to glGetProgramInfoLog OpenGL function.
    void (*glGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
    /// Pointer to glGetProgramiv OpenGL function.
    void (*glGetProgramiv)(GLuint, GLenum, GLint *);
    /// Pointer to glGetRenderbufferParameteriv OpenGL function.
    void (*glGetRenderbufferParameteriv)(GLenum, GLenum, GLint *);
    /// Pointer to glGetShaderInfoLog OpenGL function.
    void (*glGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
    /// Pointer to glGetShaderiv OpenGL function.
    void (*glGetShaderiv)(GLuint, GLenum, GLint *);
    /// Pointer to glGetShaderSource OpenGL function.
    void (*glGetShaderSource)(GLuint, GLsizei, GLsizei *, GLchar *);
    /// Pointer to glGetString OpenGL function.
    const GLubyte *(*glGetString)(GLenum);
    /// Pointer to glGetTexParameterfv OpenGL function.
    void (*glGetTexParameterfv)(GLenum, GLenum, GLfloat *);
    /// Pointer to glGetTexParameteriv OpenGL function.
    void (*glGetTexParameteriv)(GLenum, GLenum, GLint *);
    /// Pointer to glGetUniformfv OpenGL function.
    void (*glGetUniformfv)(GLuint, GLint, GLfloat *);
    /// Pointer to glGetUniformiv OpenGL function.
    void (*glGetUniformiv)(GLuint, GLint, GLint *);
    /// Pointer to glGetUniformLocation OpenGL function.
    GLint (*glGetUniformLocation)(GLuint, const GLchar *);
    /// Pointer to glGetVertexAttribfv OpenGL function.
    void (*glGetVertexAttribfv)(GLuint, GLenum, GLfloat *);
    /// Pointer to glGetVertexAttribiv OpenGL function.
    void (*glGetVertexAttribiv)(GLuint, GLenum, GLint *);
    /// Pointer to glGetVertexAttribPointerv OpenGL function.
    void (*glGetVertexAttribPointerv)(GLuint, GLenum, void **);
    /// Pointer to glHint OpenGL function.
    void (*glHint)(GLenum, GLenum);
    /// Pointer to glIsBuffer OpenGL function.
    GLboolean (*glIsBuffer)(GLuint);
    /// Pointer to glIsEnabled OpenGL function.
    GLboolean (*glIsEnabled)(GLenum);
    /// Pointer to glIsFramebuffer OpenGL function.
    GLboolean (*glIsFramebuffer)(GLuint);
    /// Pointer to glIsProgram OpenGL function.
    GLboolean (*glIsProgram)(GLuint);
    /// Pointer to glIsRenderbuffer OpenGL function.
    GLboolean (*glIsRenderbuffer)(GLuint);
    /// Pointer to glIsShader OpenGL function.
    GLboolean (*glIsShader)(GLuint);
    /// Pointer to glIsTexture OpenGL function.
    GLboolean (*glIsTexture)(GLuint);
    /// Pointer to glLineWidth OpenGL function.
    void (*glLineWidth)(GLfloat);
    /// Pointer to glLinkProgram OpenGL function.
    void (*glLinkProgram)(GLuint);
    /// Pointer to glPixelStorei OpenGL function.
    void (*glPixelStorei)(GLenum, GLint);
    /// Pointer to glPolygonOffset OpenGL function.
    void (*glPolygonOffset)(GLfloat, GLfloat);
    /// Pointer to glReadPixels OpenGL function.
    void (*glReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *);
    /// Pointer to glRenderbufferStorage OpenGL function.
    void (*glRenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei);
    /// Pointer to glSampleCoverage OpenGL function.
    void (*glSampleCoverage)(GLfloat, GLboolean);
    /// Pointer to glScissor OpenGL function.
    void (*glScissor)(GLint, GLint, GLsizei, GLsizei);
    /// Pointer to glShaderSource OpenGL function.
    void (*glShaderSource)(GLuint, GLsizei, const GLchar * const*, const GLint *);
    /// Pointer to glStencilFunc OpenGL function.
    void (*glStencilFunc)(GLenum, GLint, GLuint);
    /// Pointer to glStencilFuncSeparate OpenGL function.
    void (*glStencilFuncSeparate)(GLenum, GLenum, GLint, GLuint);
    /// Pointer to glStencilMask OpenGL function.
    void (*glStencilMask)(GLuint);
    /// Pointer to glStencilMaskSeparate OpenGL function.
    void (*glStencilMaskSeparate)(GLenum, GLuint);
    /// Pointer to glStencilOp OpenGL function.
    void (*glStencilOp)(GLenum, GLenum, GLenum);
    /// Pointer to glStencilOpSeparate OpenGL function.
    void (*glStencilOpSeparate)(GLenum, GLenum, GLenum, GLenum);
    /// Pointer to glTexImage2D OpenGL function.
    void (*glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *);
    /// Pointer to glTexParameterf OpenGL function.
    void (*glTexParameterf)(GLenum, GLenum, GLfloat);
    /// Pointer to glTexParameterfv OpenGL function.
    void (*glTexParameterfv)(GLenum, GLenum, const GLfloat *);
    /// Pointer to glTexParameteri OpenGL function.
    void (*glTexParameteri)(GLenum, GLenum, GLint);
    /// Pointer to glTexParameteriv OpenGL function.
    void (*glTexParameteriv)(GLenum, GLenum, const GLint *);
    /// Pointer to glTexSubImage2D OpenGL function.
    void (*glTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
    /// Pointer to glUniform1f OpenGL function.
    void (*glUniform1f)(GLint, GLfloat);
    /// Pointer to glUniform1fv OpenGL function.
    void (*glUniform1fv)(GLint, GLsizei, const GLfloat *);
    /// Pointer to glUniform1i OpenGL function.
    void (*glUniform1i)(GLint, GLint);
    /// Pointer to glUniform1iv OpenGL function.
    void (*glUniform1iv)(GLint, GLsizei, const GLint *);
    /// Pointer to glUniform2f OpenGL function.
    void (*glUniform2f)(GLint, GLfloat, GLfloat);
    /// Pointer to glUniform2fv OpenGL function.
    void (*glUniform2fv)(GLint, GLsizei, const GLfloat *);
    /// Pointer to glUniform2i OpenGL function.
    void (*glUniform2i)(GLint, GLint, GLint);
    /// Pointer to glUniform2iv OpenGL function.
    void (*glUniform2iv)(GLint, GLsizei, const GLint *);
    /// Pointer to glUniform3f OpenGL function.
    void (*glUniform3f)(GLint, GLfloat, GLfloat, GLfloat);
    /// Pointer to glUniform3fv OpenGL function.
    void (*glUniform3fv)(GLint, GLsizei, const GLfloat *);
    /// Pointer to glUniform3i OpenGL function.
    void (*glUniform3i)(GLint, GLint, GLint, GLint);
    /// Pointer to glUniform3iv OpenGL function.
    void (*glUniform3iv)(GLint, GLsizei, const GLint *);
    /// Pointer to glUniform4f OpenGL function.
    void (*glUniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
    /// Pointer to glUniform4fv OpenGL function.
    void (*glUniform4fv)(GLint, GLsizei, const GLfloat *);
    /// Pointer to glUniform4i OpenGL function.
    void (*glUniform4i)(GLint, GLint, GLint, GLint, GLint);
    /// Pointer to glUniform4iv OpenGL function.
    void (*glUniform4iv)(GLint, GLsizei, const GLint *);
    /// Pointer to glUniformMatrix2fv OpenGL function.
    void (*glUniformMatrix2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
    /// Pointer to glUniformMatrix3fv OpenGL function.
    void (*glUniformMatrix3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
    /// Pointer to glUniformMatrix4fv OpenGL function.
    void (*glUniformMatrix4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
    /// Pointer to glUseProgram OpenGL function.
    void (*glUseProgram)(GLuint);
    /// Pointer to glValidateProgram OpenGL function.
    void (*glValidateProgram)(GLuint);
    /// Pointer to glVertexAttrib1f OpenGL function.
    void (*glVertexAttrib1f)(GLuint, GLfloat);
    /// Pointer to glVertexAttrib1fv OpenGL function.
    void (*glVertexAttrib1fv)(GLuint, const GLfloat *);
    /// Pointer to glVertexAttrib2f OpenGL function.
    void (*glVertexAttrib2f)(GLuint, GLfloat, GLfloat);
    /// Pointer to glVertexAttrib2fv OpenGL function.
    void (*glVertexAttrib2fv)(GLuint, const GLfloat *);
    /// Pointer to glVertexAttrib3f OpenGL function.
    void (*glVertexAttrib3f)(GLuint, GLfloat, GLfloat, GLfloat);
    /// Pointer to glVertexAttrib3fv OpenGL function.
    void (*glVertexAttrib3fv)(GLuint, const GLfloat *);
    /// Pointer to glVertexAttrib4f OpenGL function.
    void (*glVertexAttrib4f)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
    /// Pointer to glVertexAttrib4fv OpenGL function.
    void (*glVertexAttrib4fv)(GLuint, const GLfloat *);
    /// Pointer to glVertexAttribPointer OpenGL function.
    void (*glVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *);
    /// Pointer to glViewport OpenGL function.
    void (*glViewport)(GLint, GLint, GLsizei, GLsizei);
};

}  // namespace gl
}  // namespace mbgl