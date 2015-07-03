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

protected:

  InSequence s;

  std::shared_ptr<Mock_renderer> renderer = std::make_shared<Mock_renderer>();
  std::shared_ptr<Mock_terminal> terminal = std::make_shared<Mock_terminal>();

  Display display;

  void expect_refresh_and_clear() {
    EXPECT_CALL(*terminal, refresh());
    EXPECT_CALL(*terminal, clear());
  }
};

TEST_F(DisplayTest, UpdateGivenSingleLine) {
  std::vector<std::string> test_rendered = { "test line" };
  EXPECT_CALL(*renderer, render())
    .WillOnce(Return(test_rendered));

  EXPECT_CALL(*terminal, print(test_rendered[0] + "\n"));
  expect_refresh_and_clear();

  display.update();
}

TEST_F(DisplayTest, UpdateGivenTwoUnidenticalLines) {
  std::vector<std::string> test_rendered = { "test line 1", "test line 2" };
  EXPECT_CALL(*renderer, render())
    .WillOnce(Return(test_rendered));

  EXPECT_CALL(*terminal, print(test_rendered[0] + "\n"));
  EXPECT_CALL(*terminal, print(test_rendered[1] + "\n"));
  expect_refresh_and_clear();

  display.update();
}
