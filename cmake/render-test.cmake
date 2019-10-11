add_executable(mbgl-render-test
    render-test/src/mbgl/render_test_runner.cpp
    render-test/src/test-runner/filesystem.hpp
    render-test/src/test-runner/allocation_index.cpp
    render-test/src/test-runner/allocation_index.hpp
    render-test/src/test-runner/filesystem.hpp
    render-test/src/test-runner/metadata.hpp
    render-test/src/test-runner/parser.cpp
    render-test/src/test-runner/parser.hpp
    render-test/src/test-runner/runner.cpp
    render-test/src/test-runner/runner.hpp
    render-test/src/test-runner/test_runner.hpp
    render-test/src/test-runner/test_runner.cpp
    expression-test/test_runner_common.cpp
    expression-test/test_runner_common.hpp
)

target_include_directories(mbgl-render-test
    PRIVATE src
    PRIVATE platform/default/include
    PRIVATE render-test/src
)

target_include_directories(
    mbgl-render-test
    PUBLIC render-test/include 
    PUBLIC include
)

target_link_libraries(mbgl-render-test PRIVATE
    mbgl-core
    mbgl-filesource
    Mapbox::Base::Extras::args
    mbgl-vendor-expected
    Mapbox::Base::Extras::filesystem
    Mapbox::Base::pixelmatch-cpp
    Mapbox::Base::Extras::rapidjson
)

mbgl_platform_render_test()

create_source_groups(mbgl-render-test)

set_target_properties(mbgl-render-test PROPERTIES FOLDER "Executables")

add_definitions(-DTEST_RUNNER_ROOT_PATH="${CMAKE_SOURCE_DIR}")
