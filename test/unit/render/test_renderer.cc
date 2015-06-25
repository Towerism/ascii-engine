#include <gtest/gtest.h>
#include <string>
#include <ascii-engine/render/renderer.hh>
#include <ascii-engine/render/renderable.hh>

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

TEST(Renderer, AddRenderable) {
  Renderable* renderable = new Renderable;
  Renderer renderer;

  renderer.add(renderable);

  EXPECT_EQ(renderable, renderer.get_renderable(0));
}

TEST(Renderer, RenderSingleCharacter) {
  std::string str = "@";
  Renderable* renderable = new Renderable(0, 0, str);
  Renderer renderer(2, 2);

  renderer.add(renderable);
  renderer.render();

  EXPECT_EQ(str, renderer.get_string_at_row(0));
}
