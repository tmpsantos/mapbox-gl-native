add_library(kdbush.hpp INTERFACE)

target_include_directories(kdbush.hpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/kdbush.hpp/include
)
