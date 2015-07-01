#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <curses_wrapper.hh>
#include <ascii-engine/display/terminal_output.hh>

class Mock_curses_wrapper : public Curses_wrapper {
public:
  MOCK_METHOD1(print, void(std::string));
};

TEST(TerminalOutput, PrintLine) {
  Mock_curses_wrapper* curses = new Mock_curses_wrapper;
  std::string test_str = "This is a test";
  EXPECT_CALL(*curses, print(test_str + "\n"));

  Terminal_output terminal(curses);
  terminal.print_line(test_str);
}
