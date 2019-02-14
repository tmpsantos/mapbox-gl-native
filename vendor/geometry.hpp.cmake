add_library(geometry.hpp INTERFACE)

target_include_directories(geometry.hpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/geometry.hpp/include
)
