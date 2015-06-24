#include <gtest/gtest.h>
#include <ascii-engine/display/renderable.hh>
#include <string>

TEST(Renderable, CreateDefault) {
  Renderable test_renderable;

  ASSERT_EQ(test_renderable.get_x(), 0);
  ASSERT_EQ(test_renderable.get_y(), 0);
  ASSERT_EQ(test_renderable.get_str(), "");
}

TEST(Renderable, CreateWithPositionAndStr) {
  int x = 5;
  int y = 6;
  std::string str = "test";

  ASSERT_EQ(test_renderable.get_x(), x);
  ASSERT_EQ(test_renderable.get_y(), y);
  ASSERT_EQ(test_renderable.get_str(), str);
}
