#include <mbgl/gl/value.hpp>
#include <mbgl/gl/gl.hpp>
#include <mbgl/gl/context.hpp>
#include <mbgl/gl/vertex_array_extension.hpp>

namespace mbgl {
namespace gl {
namespace value {

const constexpr ClearDepth::Type ClearDepth::Default;

void ClearDepth::Set(const Type& value) {
    glClearDepthf(value);
}

ClearDepth::Type ClearDepth::Get() {
    GLfloat clearDepth;
    glGetFloatv(GL_DEPTH_CLEAR_VALUE, &clearDepth);
    return clearDepth;
}

const ClearColor::Type ClearColor::Default { 0, 0, 0, 0 };

void ClearColor::Set(const Type& value) {
    glClearColor(value.r, value.g, value.b, value.a);
}

ClearColor::Type ClearColor::Get() {
    GLfloat clearColor[4];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, clearColor);
    return { clearColor[0], clearColor[1], clearColor[2], clearColor[3] };
}

const constexpr ClearStencil::Type ClearStencil::Default;

void ClearStencil::Set(const Type& value) {
    glClearStencil(value);
}

ClearStencil::Type ClearStencil::Get() {
    GLint clearStencil;
    glGetIntegerv(GL_STENCIL_CLEAR_VALUE, &clearStencil);
    return clearStencil;
}

const constexpr StencilMask::Type StencilMask::Default;

void StencilMask::Set(const Type& value) {
    glStencilMask(value);
}

StencilMask::Type StencilMask::Get() {
    GLint stencilMask;
    glGetIntegerv(GL_STENCIL_WRITEMASK, &stencilMask);
    return stencilMask;
}

const constexpr DepthMask::Type DepthMask::Default;

void DepthMask::Set(const Type& value) {
    glDepthMask(value);
}

DepthMask::Type DepthMask::Get() {
    GLboolean depthMask;
    glGetBooleanv(GL_DEPTH_WRITEMASK, &depthMask);
    return depthMask;
}

const constexpr ColorMask::Type ColorMask::Default;

void ColorMask::Set(const Type& value) {
    glColorMask(value.r, value.g, value.b, value.a);
}

ColorMask::Type ColorMask::Get() {
    GLboolean bools[4];
    glGetBooleanv(GL_COLOR_WRITEMASK, bools);
    return { static_cast<bool>(bools[0]), static_cast<bool>(bools[1]), static_cast<bool>(bools[2]),
             static_cast<bool>(bools[3]) };
}

const constexpr StencilFunc::Type StencilFunc::Default;

void StencilFunc::Set(const Type& value) {
    glStencilFunc(static_cast<GLenum>(value.func), value.ref, value.mask);
}

StencilFunc::Type StencilFunc::Get() {
    GLint func, ref, mask;
    glGetIntegerv(GL_STENCIL_FUNC, &func);
    glGetIntegerv(GL_STENCIL_REF, &ref);
    glGetIntegerv(GL_STENCIL_VALUE_MASK, &mask);
    return { static_cast<uint32_t>(func), ref, static_cast<uint32_t>(mask) };
}

const constexpr StencilTest::Type StencilTest::Default;

void StencilTest::Set(const Type& value) {
    value ? glEnable(GL_STENCIL_TEST) : glDisable(GL_STENCIL_TEST);
}

StencilTest::Type StencilTest::Get() {
    Type stencilTest;
    stencilTest = glIsEnabled(GL_STENCIL_TEST);
    return stencilTest;
}

const constexpr StencilOp::Type StencilOp::Default;

void StencilOp::Set(const Type& value) {
    glStencilOp(static_cast<GLenum>(value.sfail),
                                 static_cast<GLenum>(value.dpfail),
                                 static_cast<GLenum>(value.dppass));
}

StencilOp::Type StencilOp::Get() {
    GLint sfail, dpfail, dppass;
    glGetIntegerv(GL_STENCIL_FAIL, &sfail);
    glGetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, &dpfail);
    glGetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, &dppass);
    return { static_cast<StencilMode::Op>(sfail), static_cast<StencilMode::Op>(dpfail),
             static_cast<StencilMode::Op>(dppass) };
}

const constexpr DepthRange::Type DepthRange::Default;

void DepthRange::Set(const Type& value) {
    glDepthRangef(value.min, value.max);
}

DepthRange::Type DepthRange::Get() {
    GLfloat floats[2];
    glGetFloatv(GL_DEPTH_RANGE, floats);
    return { floats[0], floats[1] };
}

const constexpr DepthTest::Type DepthTest::Default;

void DepthTest::Set(const Type& value) {
    value ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
}

DepthTest::Type DepthTest::Get() {
    Type depthTest;
    depthTest = glIsEnabled(GL_DEPTH_TEST);
    return depthTest;
}

const constexpr DepthFunc::Type DepthFunc::Default;

void DepthFunc::Set(const DepthFunc::Type& value) {
    glDepthFunc(static_cast<GLenum>(value));
}

DepthFunc::Type DepthFunc::Get() {
    GLint depthFunc;
    glGetIntegerv(GL_DEPTH_FUNC, &depthFunc);
    return static_cast<Type>(depthFunc);
}

const constexpr Blend::Type Blend::Default;

void Blend::Set(const Type& value) {
    value ? glEnable(GL_BLEND) : glDisable(GL_BLEND);
}

Blend::Type Blend::Get() {
    Type blend;
    blend = glIsEnabled(GL_BLEND);
    return blend;
}

const constexpr BlendEquation::Type BlendEquation::Default;

void BlendEquation::Set(const Type& value) {
    glBlendEquation(static_cast<GLenum>(value));
}

BlendEquation::Type BlendEquation::Get() {
    GLint blend;
    glGetIntegerv(GL_BLEND_EQUATION_RGB, &blend);
    return static_cast<Type>(blend);
}

const constexpr BlendFunc::Type BlendFunc::Default;

void BlendFunc::Set(const Type& value) {
    glBlendFunc(static_cast<GLenum>(value.sfactor), static_cast<GLenum>(value.dfactor));
}

BlendFunc::Type BlendFunc::Get() {
    GLint sfactor, dfactor;
    glGetIntegerv(GL_BLEND_SRC_ALPHA, &sfactor);
    glGetIntegerv(GL_BLEND_DST_ALPHA, &dfactor);
    return { static_cast<ColorMode::BlendFactor>(sfactor),
             static_cast<ColorMode::BlendFactor>(dfactor) };
}

const BlendColor::Type BlendColor::Default { 0, 0, 0, 0 };

void BlendColor::Set(const Type& value) {
    glBlendColor(value.r, value.g, value.b, value.a);
}

BlendColor::Type BlendColor::Get() {
    GLfloat floats[4];
    glGetFloatv(GL_BLEND_COLOR, floats);
    return { floats[0], floats[1], floats[2], floats[3] };
}

const constexpr Program::Type Program::Default;

void Program::Set(const Type& value) {
    glUseProgram(value);
}

Program::Type Program::Get() {
    GLint program;
    glGetIntegerv(GL_CURRENT_PROGRAM, &program);
    return program;
}

const constexpr LineWidth::Type LineWidth::Default;

void LineWidth::Set(const Type& value) {
    glLineWidth(value);
}

LineWidth::Type LineWidth::Get() {
    GLfloat lineWidth;
    glGetFloatv(GL_LINE_WIDTH, &lineWidth);
    return lineWidth;
}

const constexpr ActiveTextureUnit::Type ActiveTextureUnit::Default;

void ActiveTextureUnit::Set(const Type& value) {
    glActiveTexture(GL_TEXTURE0 + value);
}

ActiveTextureUnit::Type ActiveTextureUnit::Get() {
    GLint activeTexture;
    glGetIntegerv(GL_ACTIVE_TEXTURE, &activeTexture);
    return static_cast<Type>(activeTexture - GL_TEXTURE0);
}

const constexpr Viewport::Type Viewport::Default;

void Viewport::Set(const Type& value) {
    glViewport(value.x, value.y, value.size.width, value.size.height);
}

Viewport::Type Viewport::Get() {
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    return { static_cast<int32_t>(viewport[0]), static_cast<int32_t>(viewport[1]),
             { static_cast<uint32_t>(viewport[2]), static_cast<uint32_t>(viewport[3]) } };
}

const constexpr ScissorTest::Type ScissorTest::Default;

void ScissorTest::Set(const Type& value) {
    value ? glEnable(GL_SCISSOR_TEST) : glDisable(GL_SCISSOR_TEST);
}

ScissorTest::Type ScissorTest::Get() {
    Type scissorTest;
    scissorTest = glIsEnabled(GL_SCISSOR_TEST);
    return scissorTest;
}

const constexpr BindFramebuffer::Type BindFramebuffer::Default;

void BindFramebuffer::Set(const Type& value) {
    glBindFramebuffer(GL_FRAMEBUFFER, value);
}

BindFramebuffer::Type BindFramebuffer::Get() {
    GLint binding;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &binding);
    return binding;
}

const constexpr BindRenderbuffer::Type BindRenderbuffer::Default;

void BindRenderbuffer::Set(const Type& value) {
    glBindRenderbuffer(GL_RENDERBUFFER, value);
}

BindRenderbuffer::Type BindRenderbuffer::Get() {
    GLint binding;
    glGetIntegerv(GL_RENDERBUFFER_BINDING, &binding);
    return binding;
}

const constexpr CullFace::Type CullFace::Default;

void CullFace::Set(const Type& value) {
    value == CullFaceMode::Enable ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);
}

CullFace::Type CullFace::Get() {
    GLboolean cullFace;
    cullFace = glIsEnabled(GL_CULL_FACE);
    return cullFace ? CullFaceMode::Enable : CullFaceMode::Disable;
}

const constexpr CullFaceSide::Type CullFaceSide::Default;

void CullFaceSide::Set(const Type& value) {
    glCullFace(static_cast<GLenum>(value));
}

CullFaceSide::Type CullFaceSide::Get() {
    GLint cullFaceMode;
    glGetIntegerv(GL_CULL_FACE_MODE, &cullFaceMode);
    return static_cast<Type>(cullFaceMode);
}

const constexpr FrontFace::Type FrontFace::Default;

void FrontFace::Set(const Type& value) {
    glFrontFace(static_cast<GLenum>(value));
}

FrontFace::Type FrontFace::Get() {
    GLint frontFace;
    glGetIntegerv(GL_FRONT_FACE, &frontFace);
    return static_cast<Type>(frontFace);
}

const constexpr BindTexture::Type BindTexture::Default;

void BindTexture::Set(const Type& value) {
    glBindTexture(GL_TEXTURE_2D, value);
}

BindTexture::Type BindTexture::Get() {
    GLint binding;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &binding);
    return binding;
}

const constexpr BindVertexBuffer::Type BindVertexBuffer::Default;

void BindVertexBuffer::Set(const Type& value) {
    glBindBuffer(GL_ARRAY_BUFFER, value);
}

BindVertexBuffer::Type BindVertexBuffer::Get() {
    GLint binding;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &binding);
    return binding;
}

const constexpr BindElementBuffer::Type BindElementBuffer::Default;

void BindElementBuffer::Set(const Type& value) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, value);
}

BindElementBuffer::Type BindElementBuffer::Get() {
    GLint binding;
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &binding);
    return binding;
}

const constexpr BindVertexArray::Type BindVertexArray::Default;

void BindVertexArray::Set(const Type& value, const Context& context) {
    if (auto vertexArray = context.getVertexArrayExtension()) {
        if (vertexArray->bindVertexArray) {
            vertexArray->bindVertexArray(value);
        }
    }
}

BindVertexArray::Type BindVertexArray::Get(const Context& context) {
    GLint binding = 0;
    if (context.getVertexArrayExtension()) {
#ifdef GL_VERTEX_ARRAY_BINDING
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &binding);
#elif GL_VERTEX_ARRAY_BINDING_OES
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING_OES, &binding);
#elif GL_VERTEX_ARRAY_BINDING_ARB
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING_ARB, &binding);
#elif GLVERTEX_ARRAY_BINDING_APPLE
        glGetIntegerv(GLVERTEX_ARRAY_BINDING_APPLE, &binding);
#endif
    }
    return binding;
}

const optional<AttributeBinding> VertexAttribute::Default {};

void VertexAttribute::Set(const optional<AttributeBinding>& binding, Context& context, AttributeLocation location) {
    if (binding) {
        context.vertexBuffer = binding->vertexBuffer;
        glEnableVertexAttribArray(location);
        glVertexAttribPointer(
            location,
            static_cast<GLint>(binding->attributeSize),
            static_cast<GLenum>(binding->attributeType),
            static_cast<GLboolean>(false),
            static_cast<GLsizei>(binding->vertexSize),
            reinterpret_cast<GLvoid*>(binding->attributeOffset + (binding->vertexSize * binding->vertexOffset)));
    } else {
        glDisableVertexAttribArray(location);
    }
}

const constexpr PixelStorePack::Type PixelStorePack::Default;

void PixelStorePack::Set(const Type& value) {
    assert(value.alignment == 1 || value.alignment == 2 || value.alignment == 4 ||
           value.alignment == 8);
    glPixelStorei(GL_PACK_ALIGNMENT, value.alignment);
}

PixelStorePack::Type PixelStorePack::Get() {
    Type value;
    glGetIntegerv(GL_PACK_ALIGNMENT, &value.alignment);
    return value;
}

const constexpr PixelStoreUnpack::Type PixelStoreUnpack::Default;

void PixelStoreUnpack::Set(const Type& value) {
    assert(value.alignment == 1 || value.alignment == 2 || value.alignment == 4 ||
           value.alignment == 8);
    glPixelStorei(GL_UNPACK_ALIGNMENT, value.alignment);
}

PixelStoreUnpack::Type PixelStoreUnpack::Get() {
    Type value;
    glGetIntegerv(GL_UNPACK_ALIGNMENT, &value.alignment);
    return value;
}

} // namespace value
} // namespace gl
} // namespace mbgl
