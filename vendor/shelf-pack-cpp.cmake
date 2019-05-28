add_library(shelf-pack-cpp INTERFACE)

target_include_directories(shelf-pack-cpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/shelf-pack-cpp/include
)
