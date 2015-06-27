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
  EXPECT_EQ("   ", renderer.get_line(0));
  EXPECT_EQ("   ", renderer.get_line(1));
}

TEST(Renderer, AddRenderable) {
  Renderable* renderable = new Renderable;
  Renderer renderer;

  renderer.add(renderable);

  EXPECT_EQ(renderable, renderer.get_renderable(0));
}

TEST(Renderer, RenderSingleCharacterAtOrigin) {
  Renderable* renderable = new Renderable(0, 0, "@");
  Renderer renderer(2, 2);

  renderer.add(renderable);
  renderer.render();

  EXPECT_EQ("@ ", renderer.get_line(0));
}

TEST(Renderer, RenderSingleCharacterAtNonOrigin) {
  Renderable* renderable = new Renderable(0, 1, "@");
  Renderer renderer(2, 2);

  renderer.add(renderable);
  renderer.render();

  EXPECT_EQ("  ", renderer.get_line(0));
  EXPECT_EQ("@ ", renderer.get_line(1));
}

TEST(Renderer, RenderMultipleCharacters) {
  Renderable* renderable = new Renderable(0, 1, "@#");
  Renderer renderer(2, 2);

  renderer.add(renderable);
  renderer.render();

  EXPECT_EQ("  ", renderer.get_line(0));
  EXPECT_EQ("@#", renderer.get_line(1));
}

TEST(Renderer, RenderMultipleLines) {
  Renderable* renderable = new Renderable(1, 0, "a\nb\nc");
  Renderer renderer(2, 3);

  renderer.add(renderable);
  renderer.render();

  EXPECT_EQ(" a", renderer.get_line(0));
  EXPECT_EQ(" b", renderer.get_line(1));
  EXPECT_EQ(" c", renderer.get_line(2));
}

TEST(Renderer, RenderMultipleStrings) {
  Renderable* renderable1 = new Renderable(0, 0, "aa");
  Renderable* renderable2 = new Renderable(1, 0, "b");
  Renderer renderer(2, 1);

  renderer.add(renderable1);
  renderer.add(renderable2);
  renderer.render();

  EXPECT_EQ("ab", renderer.get_line(0));
}
