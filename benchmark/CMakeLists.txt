add_library(mbgl-benchmark SHARED
    ${CMAKE_CURRENT_LIST_DIR}/api/query.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/api/render.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/function/camera_function.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/function/composite_function.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/function/source_function.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/parse/filter.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/parse/tile_mask.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/parse/vector_tile.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/mbgl/benchmark/benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/storage/offline_database.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/util/dtoa.benchmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/util/tilecover.benchmark.cpp
)

target_include_directories(mbgl-benchmark PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src
)

target_include_directories(mbgl-benchmark PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

include(${PROJECT_SOURCE_DIR}/vendor/benchmark.cmake)

target_link_libraries(mbgl-benchmark PRIVATE
    Mapbox::Maps::Core
    Mapbox::Maps::Platform
    Mapbox::Maps::GFX
    benchmark
)

add_library(Mapbox::Maps::Benchmark ALIAS mbgl-benchmark)
