find_package(CURL REQUIRED)
find_package(ICU REQUIRED i18n)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLES glesv2 REQUIRED)
pkg_search_module(EGL egl REQUIRED)
pkg_search_module(LIBUV libuv REQUIRED)

add_library(mbgl-platform-linux STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/gl_functions.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/headless_backend_egl.cpp
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
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/gfx/headless_backend.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/gfx/headless_frontend.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/gl/headless_backend.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/layermanager/layer_manager.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/asset_file_source.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/default_file_source.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/file_source.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/file_source_request.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/http_file_source.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/local_file_request.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/local_file_source.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/offline.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/offline_database.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/offline_download.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/online_file_source.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/storage/sqlite3.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/text/bidi.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/text/collator.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/text/local_glyph_rasterizer.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/text/unaccent.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/async_task.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/format_number.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/image.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/jpeg_reader.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/logging_stderr.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/png_reader.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/png_writer.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/run_loop.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/string_stdlib.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/thread.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/thread_local.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/timer.cpp
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/util/utf.cpp
)

# FIXME: Disabling because of a circular linking dependency
target_compile_definitions(mbgl-platform-linux PRIVATE
    MBGL_LAYER_CUSTOM_DISABLE_ALL
    MBGL_USE_GLES2
)

target_include_directories(mbgl-platform-linux PRIVATE
    ${PROJECT_SOURCE_DIR}/gfx/gl/src
    ${CURL_INCLUDE_DIRS}
    ${EGL_INCLUDE_DIRS}
    ${GLES_INCLUDE_DIRS}
    ${JPEG_INCLUDE_DIRS}
    ${LIBUV_INCLUDE_DIRS}
)

# FIXME: Platform should not export public headers but it
# is currently doing so because of default styles
target_include_directories(mbgl-platform-linux PUBLIC
    ${PROJECT_SOURCE_DIR}/gfx/gl/include
    ${PROJECT_SOURCE_DIR}/gfx/gl/src
    ${PROJECT_SOURCE_DIR}/platform/default/include
)

include(${PROJECT_SOURCE_DIR}/vendor/boost.cmake)
include(${PROJECT_SOURCE_DIR}/vendor/nunicode.cmake)
include(${PROJECT_SOURCE_DIR}/vendor/sqlite.cmake)

# Need to be public because this is a static library
target_link_libraries(mbgl-platform-linux PRIVATE
    ${CURL_LIBRARIES}
    ${EGL_LIBRARIES}
    ${GLES_LIBRARIES}
    ${JPEG_LIBRARIES}
    ${LIBUV_LIBRARIES}
    ICU::i18n
    Mapbox::Maps::Core
    PNG::PNG
    boost
    nunicode
    pthread
    sqlite
)

add_library(Mapbox::Maps::Platform ALIAS mbgl-platform-linux)

add_executable(mbgl-test-linux
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/test/main.cpp
)

target_compile_definitions(mbgl-test-linux PRIVATE
    WORK_DIRECTORY=${PROJECT_SOURCE_DIR}
)

target_link_libraries(mbgl-test-linux PRIVATE
    Mapbox::Maps::Core
    Mapbox::Maps::Platform
    Mapbox::Maps::Test
)

add_executable(mbgl-benchmark-linux
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/benchmark/main.cpp
)

target_link_libraries(mbgl-benchmark-linux PRIVATE
    Mapbox::Maps::Core
    Mapbox::Maps::Platform
    Mapbox::Maps::Benchmark
)

add_test(NAME mbgl-benchmark-linux COMMAND mbgl-benchmark-linux WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
add_test(NAME mbgl-test-linux COMMAND mbgl-test-linux)
