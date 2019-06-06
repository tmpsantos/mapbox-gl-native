find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(CURL REQUIRED)

pkg_search_module(GLES glesv2 REQUIRED)
pkg_search_module(EGL egl REQUIRED)
pkg_search_module(LIBUV libuv REQUIRED)

add_library(mbgl-platform-linux STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/gl_functions.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/headless_backend_egl.cpp
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
)

target_include_directories(mbgl-platform-linux PRIVATE
    ${CURL_INCLUDE_DIRS}
    ${EGL_INCLUDE_DIRS}
    ${GLES_INCLUDE_DIRS}
    ${JPEG_INCLUDE_DIRS}
    ${LIBUV_INCLUDE_DIRS}
)

# FIXME: Platform should not export public headers but it
# is currently doing so because of default styles
target_include_directories(mbgl-platform-linux PUBLIC
    ${PROJECT_SOURCE_DIR}/platform/default/include
)

include(${PROJECT_SOURCE_DIR}/vendor/icu.cmake)
include(${PROJECT_SOURCE_DIR}/vendor/nunicode.cmake)
include(${PROJECT_SOURCE_DIR}/vendor/sqlite.cmake)

# Need to be public because this is a static library
target_link_libraries(mbgl-platform-linux PRIVATE
    ${CURL_LIBRARIES}
    ${EGL_LIBRARIES}
    ${GLES_LIBRARIES}
    ${JPEG_LIBRARIES}
    ${LIBUV_LIBRARIES}
    Mapbox::Maps::Core
    Mapbox::Maps::GFX
    PNG::PNG
    icu
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
    Mapbox::Maps::GFX
    Mapbox::Maps::Test
)

add_executable(mbgl-benchmark-linux
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/benchmark/main.cpp
)

target_link_libraries(mbgl-benchmark-linux PRIVATE
    Mapbox::Maps::Core
    Mapbox::Maps::Platform
    Mapbox::Maps::GFX
    Mapbox::Maps::Benchmark
)

add_test(NAME mbgl-benchmark-linux COMMAND mbgl-benchmark-linux WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
add_test(NAME mbgl-test-linux COMMAND mbgl-test-linux)
