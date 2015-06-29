include(configure_test_suite)
include_directories(${CMAKE_SOURCE_DIR}/lib/googletest/include)

add_subdirectory(unit)

get_test_sources(TEST_SRCS)
add_executable(ascii_engine_test_suite ${TEST_SRCS})

set(TEST_SUITE_LIBS gtest gtest_main ascii_engine)
target_link_libraries(ascii_engine_test_suite ${TEST_SUITE_LIBS})

run_test(ascii_engine_test_suite)

if (ENABLE_COVERAGE AND NOT WIN32 AND NOT APPLE)
  include(code_coverage)
  setup_target_for_coverage(
    coverage
    ascii_engine_test_suite
    coverage
  )
endif()
