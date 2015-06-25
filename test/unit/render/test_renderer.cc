#include <gtest/gtest.h>
#include <string>
#include <ascii-engine/render/renderer.hh>
#include <ascii-engine/render/renderable.hh>

TEST(Renderer, CreateDefault) {
  Renderer renderer;

  EXPECT_EQ(0, renderer.get_width());
  EXPECT_EQ(0, renderer.get_height());
  EXPECT_TRUE(renderer.char_matrix_is_empty());
}

TEST(Renderer, CreateWithDimensions) {
  int width = 3;
  int height = 2;

  Renderer renderer(3, 2);

  EXPECT_EQ(width, renderer.get_width());
  EXPECT_EQ(height, renderer.get_height());
  EXPECT_EQ("   ", renderer.get_string_at_row(0));
  EXPECT_EQ("   ", renderer.get_string_at_row(1));
}

TEST(Renderer, AddRenderable) {
  Renderable* renderable = new Renderable;
  Renderer renderer;

  renderer.add(renderable);

  EXPECT_EQ(renderable, renderer.get_renderable(0));
}

TEST(Renderer, RenderSingleCharacterAtOrigin) {
  std::string str = "@";
  Renderable* renderable = new Renderable(0, 0, str);
  Renderer renderer(2, 2);

  renderer.add(renderable);
  renderer.render();

  EXPECT_EQ(str, renderer.get_string_at_row(0));
}
