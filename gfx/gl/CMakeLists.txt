if(TARGET Mapbox::Maps::GFX)
    message("Mapbox::Maps::GFX already defined, not building OpenGL GFX")
    return()
endif()

add_library(mbgl-gfx-gl STATIC
)

# FIXME: "src" should not be public, but looks like the platform
# HeadlessBackend depends on it. We should probably move it to here.
target_include_directories(mbgl-gfx-gl PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(mbgl-gfx-gl PRIVATE
    Mapbox::Maps::Core
)

add_library(Mapbox::Maps::GFX ALIAS mbgl-gfx-gl)
