include_directories(../lib/googletest/include)
add_subdirectory(ascii-engine)

get_test_sources(TEST_SRCS)

add_executable(ascii_engine_test_suite ${TEST_SRCS})

set(TEST_SUITE_LIBS gtest gtest_main ascii_engine)
target_link_libraries(ascii_engine_test_suite ${TEST_SUITE_LIBS})

run_test(ascii_engine_test_suite)