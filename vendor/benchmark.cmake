add_library(benchmark STATIC
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/commandlineflags.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/console_reporter.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/complexity.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/csv_reporter.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/colorprint.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/sleep.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/benchmark.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/counter.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/benchmark_register.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/statistics.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/json_reporter.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/reporter.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/string_util.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/sysinfo.cc
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/src/timers.cc
)

target_compile_definitions(benchmark PRIVATE
    HAVE_STEADY_CLOCK
)

target_include_directories(benchmark SYSTEM PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/benchmark/include
)
