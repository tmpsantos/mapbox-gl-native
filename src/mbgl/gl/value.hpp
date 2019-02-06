#pragma once

#include <mbgl/gl/depth_mode.hpp>
#include <mbgl/gl/gl_functions.hpp>
#include <mbgl/gl/stencil_mode.hpp>
#include <mbgl/gl/color_mode.hpp>
#include <mbgl/gl/cull_face_mode.hpp>
#include <mbgl/gl/attribute.hpp>
#include <mbgl/util/color.hpp>
#include <mbgl/util/size.hpp>
#include <mbgl/util/range.hpp>

namespace mbgl {
namespace gl {

class Context;

namespace value {

struct ClearDepth : private GLFunctions {
    using Type = float;
    static const constexpr Type Default = 1;
    static void Set(const Type&);
    static Type Get();
};

struct ClearColor : private GLFunctions {
    using Type = Color;
    static const Type Default;
    static void Set(const Type&);
    static Type Get();
};

struct ClearStencil : private GLFunctions {
    using Type = int32_t;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct StencilMask : private GLFunctions {
    using Type = uint32_t;
    static const constexpr Type Default = ~0u;
    static void Set(const Type&);
    static Type Get();
};

struct DepthMask : private GLFunctions {
    using Type = bool;
    static const constexpr Type Default = true;
    static void Set(const Type&);
    static Type Get();
};

struct ColorMask : private GLFunctions {
    using Type = ColorMode::Mask;
    static const constexpr Type Default = { true, true, true, true };
    static void Set(const Type&);
    static Type Get();
};

struct StencilFunc : private GLFunctions {
    struct Type {
        uint32_t func;
        int32_t ref;
        uint32_t mask;
    };
    static const constexpr Type Default = { StencilMode::Always::func, 0, ~0u };
    static void Set(const Type&);
    static Type Get();
};

constexpr bool operator!=(const StencilFunc::Type& a, const StencilFunc::Type& b) {
    return a.func != b.func || a.ref != b.ref || a.mask != b.mask;
}

struct StencilTest : private GLFunctions {
    using Type = bool;
    static const constexpr Type Default = false;
    static void Set(const Type&);
    static Type Get();
};

struct StencilOp : private GLFunctions {
    struct Type {
        StencilMode::Op sfail;
        StencilMode::Op dpfail;
        StencilMode::Op dppass;
    };
    static const constexpr Type Default = { StencilMode::Keep, StencilMode::Keep, StencilMode::Keep };
    static void Set(const Type&);
    static Type Get();
};

constexpr bool operator!=(const StencilOp::Type& a, const StencilOp::Type& b) {
    return a.sfail != b.sfail || a.dpfail != b.dpfail || a.dppass != b.dppass;
}

struct DepthRange : private GLFunctions {
    using Type = Range<float>;
    static const constexpr Type Default = { 0, 1 };
    static void Set(const Type&);
    static Type Get();
};

struct DepthTest : private GLFunctions {
    using Type = bool;
    static const constexpr Type Default = false;
    static void Set(const Type&);
    static Type Get();
};

struct DepthFunc : private GLFunctions {
    using Type = DepthMode::Function;
    static const constexpr Type Default = DepthMode::Less;
    static void Set(const Type&);
    static Type Get();
};

struct Blend : private GLFunctions {
    using Type = bool;
    static const constexpr Type Default = true;
    static void Set(const Type&);
    static Type Get();
};

struct BlendEquation : private GLFunctions {
    using Type = ColorMode::BlendEquation;
    static const constexpr Type Default = ColorMode::BlendEquation::Add;
    static void Set(const Type&);
    static Type Get();
};

struct BlendFunc : private GLFunctions {
    struct Type {
        ColorMode::BlendFactor sfactor;
        ColorMode::BlendFactor dfactor;
    };
    static const constexpr Type Default = { ColorMode::One, ColorMode::Zero };
    static void Set(const Type&);
    static Type Get();
};

constexpr bool operator!=(const BlendFunc::Type& a, const BlendFunc::Type& b) {
    return a.sfactor != b.sfactor || a.dfactor != b.dfactor;
}

struct BlendColor : private GLFunctions {
    using Type = Color;
    static const Type Default;
    static void Set(const Type&);
    static Type Get();
};

struct Program : private GLFunctions {
    using Type = gl::ProgramID;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct LineWidth : private GLFunctions {
    using Type = float;
    static const constexpr Type Default = 1;
    static void Set(const Type&);
    static Type Get();
};

struct ActiveTextureUnit : private GLFunctions {
    using Type = TextureUnit;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct Viewport : private GLFunctions {
    struct Type {
        int32_t x;
        int32_t y;
        Size size;
    };
    static const constexpr Type Default = { 0, 0, { 0, 0 } };
    static void Set(const Type&);
    static Type Get();
};

struct ScissorTest : private GLFunctions {
    using Type = bool;
    static const constexpr Type Default = false;
    static void Set(const Type&);
    static Type Get();
};

constexpr bool operator!=(const Viewport::Type& a, const Viewport::Type& b) {
    return a.x != b.x || a.y != b.y || a.size != b.size;
}

constexpr bool operator==(const Viewport::Type& a, const Viewport::Type& b) {
    return !(a != b);
}

struct BindFramebuffer : private GLFunctions {
    using Type = FramebufferID;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct BindRenderbuffer : private GLFunctions {
    using Type = RenderbufferID;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct CullFace : private GLFunctions {
    using Type = CullFaceMode::CullFace;
    static const constexpr Type Default = CullFaceMode::Disable;
    static void Set(const Type&);
    static Type Get();
};

struct CullFaceSide : private GLFunctions {
    using Type = CullFaceMode::CullFaceSide;
    static const constexpr Type Default = CullFaceMode::Back;
    static void Set(const Type&);
    static Type Get();
};

struct FrontFace : private GLFunctions {
    using Type = CullFaceMode::FrontFace;
    static const constexpr Type Default = CullFaceMode::CounterClockwise;
    static void Set(const Type&);
    static Type Get();
};

struct BindTexture : private GLFunctions {
    using Type = gl::TextureID;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct BindVertexBuffer : private GLFunctions {
    using Type = gl::BufferID;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct BindElementBuffer : private GLFunctions {
    using Type = gl::BufferID;
    static const constexpr Type Default = 0;
    static void Set(const Type&);
    static Type Get();
};

struct BindVertexArray : private GLFunctions {
    using Type = gl::VertexArrayID;
    static const constexpr Type Default = 0;
    static void Set(const Type&, const Context&);
    static Type Get(const Context&);
};

struct VertexAttribute : private GLFunctions {
    using Type = optional<gl::AttributeBinding>;
    static const Type Default;
    static void Set(const Type&, Context&, AttributeLocation);
};

struct PixelStorePack : private GLFunctions {
    using Type = PixelStorageType;
    static const constexpr Type Default = { 4 };
    static void Set(const Type&);
    static Type Get();
};

struct PixelStoreUnpack : private GLFunctions {
    using Type = PixelStorageType;
    static const constexpr Type Default = { 4 };
    static void Set(const Type&);
    static Type Get();
};

} // namespace value
} // namespace gl
} // namespace mbgl
