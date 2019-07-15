if(__MBGL_GFX__)
    message("Mapbox::Maps graphics backend already defined, not building OpenGL GFX")
    return()
endif()

set(__MBGL_GFX__ TRUE)

target_sources(mbgl-core PRIVATE
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/attribute.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/command_encoder.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/context.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/debugging_extension.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/enum.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/object.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/offscreen_texture.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/render_pass.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/renderer_backend.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/texture.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/uniform.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/upload_pass.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/value.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/gl/vertex_array.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/platform/gl_functions.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/background.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/background_pattern.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/circle.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/clipping_mask.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/collision_box.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/collision_circle.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/debug.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/fill.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/fill_extrusion.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/fill_extrusion_pattern.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/fill_outline.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/fill_outline_pattern.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/fill_pattern.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/heatmap.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/heatmap_texture.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/hillshade.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/hillshade_prepare.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/line.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/line_gradient.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/line_pattern.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/line_sdf.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/raster.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/shader_source.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/shaders.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/symbol_icon.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/symbol_sdf_icon.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/programs/gl/symbol_sdf_text.cpp
    ${PROJECT_SOURCE_DIR}/gfx/gl/src/mbgl/renderer/layers/render_custom_layer.cpp
)

target_include_directories(mbgl-core PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src
)

target_include_directories(mbgl-core PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)
