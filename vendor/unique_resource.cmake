add_library(unique_resource INTERFACE)

target_include_directories(unique_resource SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/unique_resource
)
