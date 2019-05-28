add_library(optional INTERFACE)

target_include_directories(optional SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/optional/include
)
