#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <ascii-engine/display/display.hh>
#include <ascii-engine/display/output.hh>
#include <ascii-engine/render/renderer.hh>

class Mock_renderer : public Renderer {
public:

  MOCK_METHOD0(render, std::vector<std::string>());
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

  Display display(renderer, output);
  display.update();
}
