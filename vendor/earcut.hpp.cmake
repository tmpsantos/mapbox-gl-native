add_library(earcut.hpp INTERFACE)

target_include_directories(earcut.hpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/earcut.hpp/include
)
