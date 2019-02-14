add_library(boost INTERFACE)

target_include_directories(boost SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/boost/include
)
