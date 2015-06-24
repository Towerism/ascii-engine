include_directories(../lib/googletest/include)
add_subdirectory(ascii-engine)

get_test_sources(TEST_SRCS)

set(ASCII_ENGINE_TEST_SUITE_SRCS main.cc ${TEST_SRCS})
add_executable(ascii_engine_test_suite ${ASCII_ENGINE_TEST_SUITE_SRCS} )

target_link_libraries(ascii_engine_test_suite gtest display)

run_test(ascii_engine_test_suite)