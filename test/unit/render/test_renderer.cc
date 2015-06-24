#include <gtest/gtest.h>
#include <ascii_engine/render/renderer.hh>

TEST(Renderer, CreateDefault) {
  Renderer renderer;

  ASSERT_EQ(renderer.get_width(), 0);
  ASSERT_EQ(renderer.get_height(), 0);
}

TEST(Renderer, CreateWithDimensions) {
  int width = 5;
  int height = 6;

  Renderer renderer(5, 6);

  ASSERT_EQ(renderer.get_width(), width);
  ASSERT_EQ(renderer.get_height(), height);
}
