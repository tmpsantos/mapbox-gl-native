add_library(jni.hpp INTERFACE)

target_include_directories(jni.hpp SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/jni.hpp/include
)
