#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <ascii-engine/display/display.hh>
#include <ascii-engine/display/output.hh>
#include <ascii-engine/render/renderer.hh>

class Mock_renderer : public Renderer {
public:

  MOCK_METHOD1(add, void(Renderable*));
  MOCK_METHOD0(render, std::vector<std::string>());
  MOCK_CONST_METHOD0(get_width, int());
  MOCK_CONST_METHOD0(get_height, int());
  MOCK_CONST_METHOD1(get_renderable, Renderable*(int));
};

class Mock_output : public Output {
public:

  MOCK_METHOD1(print_line, void(std::string));
  MOCK_METHOD0(refresh, void());
};

using ::testing::Return;
using ::testing::InSequence;

TEST(Display, UpdateRendersAndPrints) {
  InSequence s;

  Mock_renderer* renderer = new Mock_renderer;
  std::vector<std::string> test_rendered = { "  ", "01" };
  ON_CALL(*renderer, render())
    .WillByDefault(Return(test_rendered));
  EXPECT_CALL(*renderer, render());

  Mock_output* output = new Mock_output;
  EXPECT_CALL(*output, print_line("  "));
  EXPECT_CALL(*output, print_line("01"));
  EXPECT_CALL(*output, refresh());

  Display display(renderer, output);
  display.update();
}
