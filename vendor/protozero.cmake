add_library(protozero INTERFACE)

target_include_directories(protozero SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/protozero/include
)
