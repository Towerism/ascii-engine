set(TEST_RENDER_SRCS test_create_renderable.cc)
add_executable(test_render ${TEST_RENDER_SRCS})
target_link_libraries(test_render gtest gtest_main)

gtest_test_exec(test_render)