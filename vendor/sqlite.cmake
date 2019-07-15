if(__SQLITE_CMAKE__)
    return()
endif()

set(__SQLITE_CMAKE__ TRUE)

add_library(sqlite STATIC
    ${CMAKE_CURRENT_LIST_DIR}/sqlite/src/sqlite3.c
)

include(CheckSymbolExists)
check_symbol_exists("strerror_r" "string.h" MBGL_SQLITE3_HAVE_STRERROR_R)

if(MBGL_SQLITE3_HAVE_STRERROR_R)
    target_compile_definitions(sqlite PRIVATE
        HAVE_STRERROR_R
    )
endif()

# So we don't need to link with -ldl
target_compile_definitions(sqlite PRIVATE
    SQLITE_OMIT_LOAD_EXTENSION
    SQLITE_THREADSAFE
)

target_include_directories(sqlite SYSTEM INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/sqlite/include
)
