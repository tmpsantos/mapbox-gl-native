add_library(pixelmatch-cpp INTERFACE)

target_include_directories(pixelmatch-cpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/pixelmatch-cpp/include
)
