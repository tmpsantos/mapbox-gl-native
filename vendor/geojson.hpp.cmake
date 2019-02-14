add_library(geojson.hpp INTERFACE)

target_include_directories(geojson.hpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/geojson.hpp/include
)
