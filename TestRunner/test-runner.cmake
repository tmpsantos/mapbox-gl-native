add_library(
        mbgl-android-test-runner SHARED
        ${MBGL_ROOT}/TestRunner/app/src/main/cpp/native_test_runner_driver.cpp
)

target_include_directories(
        mbgl-android-test-runner
        PUBLIC
        ${MBGL_ROOT}/render-test/include
        ${MBGL_ROOT}/include
)

target_link_libraries(
        mbgl-android-test-runner
        PRIVATE  Mapbox::Base::jni.hpp mapbox-gl mbgl-render-test
)

# Android has no concept of MinSizeRel on android.toolchain.cmake and provides configurations tuned for binary size. We can push it a bit
# more with code folding and LTO.

set_target_properties( mbgl-android-test-runner PROPERTIES LINK_FLAGS_RELEASE "-fuse-ld=gold -O2 -flto -Wl,--icf=safe")