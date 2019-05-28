add_library(variant INTERFACE)

target_include_directories(variant SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/variant/include
)
