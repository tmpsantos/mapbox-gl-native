#include <mbgl/gl/gl.hpp>

#include <cassert>

namespace {

mbgl::gl::GLFunctionPointers& getPointers() {
    static mbgl::gl::GLFunctionPointers pointers;

    return pointers;
}

}  // namespace

namespace mbgl {
namespace gl {

const GLFunctionPointers& getGLFunctionPointers() {
    return getPointers();
}

void setGLFunctionPointers(const GLFunctionPointers& pointers) {
    assert(getPointers().glClear == nullptr);

    getPointers() = pointers;
}

}  // namespace gl
}  // namespace mbgl
