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
  MOCK_METHOD0(render, std::vector<std::string>());
  MOCK_CONST_METHOD0(get_width, int());
  MOCK_CONST_METHOD0(get_height, int());
  MOCK_CONST_METHOD1(get_renderable, Renderable*(int));
};

class Mock_terminal : public Terminal {
public:
  MOCK_METHOD1(print, void(std::string));
  MOCK_METHOD0(refresh, void());
};

using ::testing::Return;
using ::testing::InSequence;
using ::testing::StrictMock;
using ::testing::NiceMock;

TEST(Display, UpdateGivenSingleLine) {
  InSequence s;

  NiceMock<Mock_renderer>* renderer = new NiceMock<Mock_renderer>;
  std::vector<std::string> test_rendered = { "test line" };
  ON_CALL(*renderer, render())
    .WillByDefault(Return(test_rendered));

  StrictMock<Mock_terminal>* terminal = new StrictMock<Mock_terminal>;
  EXPECT_CALL(*terminal, print(test_rendered[0] + "\n"));
  EXPECT_CALL(*terminal, refresh());

  Display display(renderer, terminal);
  display.update();
}

TEST(Display, UpdateGivenTwoUnidenticalLines) {
  InSequence s;

  NiceMock<Mock_renderer>* renderer = new NiceMock<Mock_renderer>;
  std::vector<std::string> test_rendered = { "test line 1", "test line 2" };
  ON_CALL(*renderer, render())
    .WillByDefault(Return(test_rendered));

  StrictMock<Mock_terminal>* terminal = new StrictMock<Mock_terminal>;
  EXPECT_CALL(*terminal, print(test_rendered[0] + "\n"));
  EXPECT_CALL(*terminal, print(test_rendered[1] + "\n"));
  EXPECT_CALL(*terminal, refresh());

  Display display(renderer, terminal);
  display.update();
}
