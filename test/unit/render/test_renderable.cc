#include <gtest/gtest.h>
#include <ascii-engine/render/renderable.hh>
#include <string>

TEST(Renderable, CreateDefault) {
  Renderable test_renderable;

  EXPECT_EQ(0, test_renderable.get_x());
  EXPECT_EQ(0, test_renderable.get_y());
  EXPECT_EQ("", test_renderable.get_str());
}

TEST(Renderable, CreateWithPositionAndStr) {
  int x = 5;
  int y = 6;
  std::string str = "test";

  Renderable test_renderable(x, y, str);

  EXPECT_EQ(x, test_renderable.get_x());
  EXPECT_EQ(y, test_renderable.get_y());
  EXPECT_EQ(str, test_renderable.get_str());
}
