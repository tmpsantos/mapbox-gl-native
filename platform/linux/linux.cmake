find_package(CURL REQUIRED)
find_package(ICU REQUIRED i18n)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLES glesv2 REQUIRED)
pkg_search_module(EGL egl REQUIRED)
pkg_search_module(LIBUV libuv REQUIRED)

target_sources(mbgl-core PRIVATE
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

target_compile_definitions(mbgl-core PRIVATE
    MBGL_USE_GLES2
)

target_include_directories(mbgl-core PRIVATE
    ${PROJECT_SOURCE_DIR}/platform/default/include
    ${CURL_INCLUDE_DIRS}
    ${EGL_INCLUDE_DIRS}
    ${GLES_INCLUDE_DIRS}
    ${JPEG_INCLUDE_DIRS}
    ${LIBUV_INCLUDE_DIRS}
)

include(${PROJECT_SOURCE_DIR}/vendor/nunicode.cmake)
include(${PROJECT_SOURCE_DIR}/vendor/sqlite.cmake)

target_link_libraries(mbgl-core PRIVATE
    ${CURL_LIBRARIES}
    ${EGL_LIBRARIES}
    ${GLES_LIBRARIES}
    ${JPEG_LIBRARIES}
    ${LIBUV_LIBRARIES}
    ICU::i18n
    PNG::PNG
    nunicode
    sqlite
)

add_executable(mbgl-test-linux
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/test/main.cpp
)

target_compile_definitions(mbgl-test-linux PRIVATE
    WORK_DIRECTORY=${PROJECT_SOURCE_DIR}
)

target_link_libraries(mbgl-test-linux PRIVATE
    Mapbox::Maps::Test
)

add_executable(mbgl-benchmark-linux
    ${PROJECT_SOURCE_DIR}/platform/default/src/mbgl/benchmark/main.cpp
)

target_link_libraries(mbgl-benchmark-linux PRIVATE
    Mapbox::Maps::Benchmark
)

add_test(NAME mbgl-benchmark-linux COMMAND mbgl-benchmark-linux WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
add_test(NAME mbgl-test-linux COMMAND mbgl-test-linux)
