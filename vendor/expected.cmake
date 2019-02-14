add_library(expected INTERFACE)

target_include_directories(expected SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/expected/include
)
