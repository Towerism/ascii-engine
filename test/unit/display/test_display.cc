#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <ascii-engine/display/display.hh>
#include "mocks.hh"

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
