add_library(gtest STATIC
    ${CMAKE_CURRENT_LIST_DIR}/gtest/src/gtest-death-test.cc
    ${CMAKE_CURRENT_LIST_DIR}/gtest/src/gtest-filepath.cc
    ${CMAKE_CURRENT_LIST_DIR}/gtest/src/gtest-port.cc
    ${CMAKE_CURRENT_LIST_DIR}/gtest/src/gtest-printers.cc
    ${CMAKE_CURRENT_LIST_DIR}/gtest/src/gtest-test-part.cc
    ${CMAKE_CURRENT_LIST_DIR}/gtest/src/gtest-typed-test.cc
    ${CMAKE_CURRENT_LIST_DIR}/gtest/src/gtest.cc
)

target_include_directories(gtest PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/gtest/include
)

target_include_directories(gtest SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/gtest/include
)
