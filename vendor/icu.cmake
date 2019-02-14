add_library(icu STATIC
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/cmemory.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/cstring.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/ubidi.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/ubidi_props.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/ubidiln.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/ubidiwrt.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/uchar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/udataswp.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/uinvchar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/umath.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/ushape.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/ustring.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/utf_impl.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/utrie2.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icu/src/utypes.cpp
)

target_compile_definitions(icu PRIVATE
    UCONFIG_NO_BREAK_ITERATION=1
    UCONFIG_NO_LEGACY_CONVERSION=1
    U_CHARSET_IS_UTF8=1
    U_CHAR_TYPE=uint_least16_t
    U_HAVE_ATOMIC=1
    U_HAVE_STRTOD_L=0
    _REENTRANT
)

target_compile_options(icu PRIVATE
    -Wno-error
    -Wno-shorten-64-to-32
)

target_include_directories(icu SYSTEM PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/icu/include
)
