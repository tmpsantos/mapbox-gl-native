add_library(cheap-ruler-cpp INTERFACE)

target_include_directories(cheap-ruler-cpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/cheap-ruler-cpp/include
)

