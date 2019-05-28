add_library(supercluster.hpp INTERFACE)

target_include_directories(supercluster.hpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/supercluster.hpp/include
)
