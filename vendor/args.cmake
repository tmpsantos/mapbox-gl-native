if(__ARGS_CMAKE__)
    return()
endif()

set(__ARGS_CMAKE__ TRUE PARENT_SCOPE)

add_library(args INTERFACE)

target_include_directories(args SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/args
)
