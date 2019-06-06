if(TARGET Mapbox::Maps::GFX)
    message("Mapbox::Maps::GFX already defined, not building OpenGL GFX")
    return()
endif()

add_library(mbgl-gfx-gl STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/attribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/command_encoder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/context.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/debugging_extension.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/enum.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/object.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/offscreen_texture.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/render_pass.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/renderer_backend.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/texture.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/uniform.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/upload_pass.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/value.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/gl/vertex_array.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/platform/gl_functions.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/background.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/background_pattern.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/circle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/clipping_mask.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/collision_box.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/collision_circle.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/debug.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/fill.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/fill_extrusion.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/fill_extrusion_pattern.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/fill_outline.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/fill_outline_pattern.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/fill_pattern.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/heatmap.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/heatmap_texture.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/hillshade.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/hillshade_prepare.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/line.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/line_gradient.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/line_pattern.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/line_sdf.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/raster.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/shader_source.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/shaders.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/symbol_icon.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/symbol_sdf_icon.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/programs/gl/symbol_sdf_text.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/renderer/layers/render_custom_layer.cpp
)

# FIXME: "src" should not be public, but looks like the platform
# HeadlessBackend depends on it. We should probably move it to here.
target_include_directories(mbgl-gfx-gl PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(mbgl-gfx-gl PRIVATE
    Mapbox::Maps::Core
)

target_compile_definitions(mbgl-gfx-gl PUBLIC
    MBGL_USE_GLES2
)

add_library(Mapbox::Maps::GFX ALIAS mbgl-gfx-gl)
