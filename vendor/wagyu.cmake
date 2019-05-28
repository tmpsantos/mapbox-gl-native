add_library(wagyu INTERFACE)

target_include_directories(wagyu SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/wagyu/include
)
