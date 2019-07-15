find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW glfw3 REQUIRED)

add_executable(mbgl-glfw
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/glfw_view.cpp
    ${CMAKE_CURRENT_LIST_DIR}/glfw_gl_backend.cpp
    ${CMAKE_CURRENT_LIST_DIR}/glfw_renderer_frontend.cpp
    ${CMAKE_CURRENT_LIST_DIR}/settings_json.cpp
)

target_include_directories(mbgl-glfw PRIVATE
    ${GLFW_INCLUDE_DIRS}
)

include(${PROJECT_SOURCE_DIR}/vendor/args.cmake)
include(${PROJECT_SOURCE_DIR}/vendor/cheap-ruler-cpp.cmake)

target_link_libraries(mbgl-glfw PRIVATE
    ${GLFW_LIBRARIES}
    Mapbox::Maps::Core
    args
    cheap-ruler-cpp
)
