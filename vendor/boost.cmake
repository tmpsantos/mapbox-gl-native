if(__BOOST_CMAKE__)
    return()
endif()

set(__BOOST_CMAKE__ TRUE PARENT_SCOPE)

add_library(boost INTERFACE)

target_include_directories(boost SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/boost/include
)
