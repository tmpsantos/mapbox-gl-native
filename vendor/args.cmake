add_library(args INTERFACE)

target_include_directories(args SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/args
)
