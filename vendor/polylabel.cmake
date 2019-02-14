add_library(polylabel INTERFACE)

target_include_directories(polylabel SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/polylabel/include
)
