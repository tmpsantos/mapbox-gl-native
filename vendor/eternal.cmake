add_library(eternal INTERFACE)

target_include_directories(eternal SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/eternal/include
)
