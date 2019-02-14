add_library(vector-tile INTERFACE)

target_include_directories(vector-tile SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/vector-tile/include
)
