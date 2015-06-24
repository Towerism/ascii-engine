#include <gtest/gtest.h>
#include <ascii-engine/render/renderer.hh>

TEST(Renderer, CreateDefault) {
  Renderer renderer;

  EXPECT_EQ(0, renderer.get_width());
  EXPECT_EQ(0, renderer.get_height());
}

TEST(Renderer, CreateWithDimensions) {
  int width = 5;
  int height = 6;

  Renderer renderer(5, 6);

  EXPECT_EQ(width, renderer.get_width());
  EXPECT_EQ(height, renderer.get_height());
}
