add_library(geojson-vt-cpp INTERFACE)

target_include_directories(geojson-vt-cpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/geojson-vt-cpp/include
)
