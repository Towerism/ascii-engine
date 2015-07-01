#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <terminal_interface.hh>
#include <ascii-engine/display/terminal_output.hh>

class Mock_terminal : public Terminal_interface {
public:
  MOCK_METHOD1(print, void(std::string));
  MOCK_METHOD0(refresh, void());
};

TEST(TerminalOutput, PrintLine) {
  Mock_terminal terminal;
  std::string test_str = "This is a test";
  EXPECT_CALL(terminal, print(test_str + "\n"));

  Terminal_output output(&terminal);
  output.print_line(test_str);
}

TEST(TerminalOutput, Refresh) {
  Mock_terminal terminal;
  EXPECT_CALL(terminal, refresh());

  Terminal_output output(&terminal);
  output.refresh();
}
