#include <string>
#include "terminal_output.hh"

Terminal_output::Terminal_output(Curses_wrapper* curses) : curses(curses) {

}

void Terminal_output::print_line(std::string line) {
  curses->print(line.append("\n"));
}
