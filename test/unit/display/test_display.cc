#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <ascii-engine/display/display.hh>
#include <ascii-engine/render/renderer.hh>
#include <terminal.hh>

class Mock_renderer : public Renderer {
public:
  MOCK_METHOD1(add, void(Renderable*));
  MOCK_METHOD0(render,
  std::vector<std::string>());
  MOCK_CONST_METHOD0(get_width, int());
  MOCK_CONST_METHOD0(get_height, int());
  MOCK_CONST_METHOD1(get_renderable, Renderable*(int));
};

class Mock_terminal : public Terminal {
public:
  MOCK_METHOD1(print, void(std::string));
  MOCK_METHOD0(refresh, void());
  MOCK_METHOD0(hard_refresh, void());
  MOCK_METHOD0(clear, void());
};

using ::testing::Return;
using ::testing::InSequence;
using ::testing::StrictMock;
using ::testing::NiceMock;

class DisplayTest : public ::testing::Test {
public:
  DisplayTest() : display(renderer, terminal) { }

  InSequence s;

  Mock_renderer* renderer = new Mock_renderer;
  StrictMock<Mock_terminal>* terminal = new StrictMock<Mock_terminal>;

  Display display;
};

TEST_F(DisplayTest, UpdateGivenSingleLine) {
  std::vector<std::string> test_rendered = { "test line" };
  EXPECT_CALL(*renderer, render())
    .WillOnce(Return(test_rendered));

  EXPECT_CALL(*terminal, print(test_rendered[0] + "\n"));
  EXPECT_CALL(*terminal, hard_refresh());

  display.update();
}

TEST_F(DisplayTest, UpdateGivenTwoUnidenticalLines) {
  std::vector<std::string> test_rendered = { "test line 1", "test line 2" };
  EXPECT_CALL(*renderer, render())
    .WillOnce(Return(test_rendered));

  EXPECT_CALL(*terminal, print(test_rendered[0] + "\n"));
  EXPECT_CALL(*terminal, print(test_rendered[1] + "\n"));
  EXPECT_CALL(*terminal, hard_refresh());

  display.update();
}
