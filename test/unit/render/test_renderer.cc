#include <gtest/gtest.h>
#include <string>
#include <ascii-engine/render/renderer.hh>
#include <ascii-engine/render/renderable.hh>

TEST(Renderer, CreateDefault) {
  Renderer renderer;
  renderer.render();
  std::vector<std::string> lines = renderer.display();

  EXPECT_EQ(0, renderer.get_width());
  EXPECT_EQ(0, renderer.get_height());
  EXPECT_TRUE(lines.empty());
}

TEST(Renderer, CreateWithDimensions) {
  int width = 3;
  int height = 2;

  Renderer renderer(3, 2);
  renderer.render();
  std::vector<std::string> lines = renderer.display();

  EXPECT_EQ(width, renderer.get_width());
  EXPECT_EQ(height, renderer.get_height());
  EXPECT_EQ("   ", lines[0]);
  EXPECT_EQ("   ", lines[1]);
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
  std::vector<std::string> lines = renderer.display();

  EXPECT_EQ("@ ", lines[0]);
}

TEST(Renderer, RenderSingleCharacterAtNonOrigin) {
  Renderable* renderable = new Renderable(0, 1, "@");
  Renderer renderer(2, 2);

  renderer.add(renderable);
  renderer.render();
  std::vector<std::string> lines = renderer.display();

  EXPECT_EQ("  ", lines[0]);
  EXPECT_EQ("@ ", lines[1]);
}

TEST(Renderer, RenderMultipleCharacters) {
  Renderable* renderable = new Renderable(0, 1, "@#");
  Renderer renderer(2, 2);

  renderer.add(renderable);
  renderer.render();
  std::vector<std::string> lines = renderer.display();

  EXPECT_EQ("  ", lines[0]);
  EXPECT_EQ("@#", lines[1]);
}

TEST(Renderer, RenderMultipleLines) {
  Renderable* renderable = new Renderable(1, 0, "a\nb\nc");
  Renderer renderer(2, 3);

  renderer.add(renderable);
  renderer.render();
  std::vector<std::string> lines = renderer.display();

  EXPECT_EQ(" a", lines[0]);
  EXPECT_EQ(" b", lines[1]);
  EXPECT_EQ(" c", lines[2]);
}

TEST(Renderer, RenderMultipleStrings) {
  Renderable* renderable1 = new Renderable(0, 0, "aa");
  Renderable* renderable2 = new Renderable(1, 0, "b");
  Renderer renderer(2, 1);

  renderer.add(renderable1);
  renderer.add(renderable2);
  renderer.render();
  std::vector<std::string> lines = renderer.display();

  EXPECT_EQ("ab", lines[0]);
}
