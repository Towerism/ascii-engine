#include <string>
#include <curses.h>
#include <curses_wrapper.hh>
#include "terminal_output.hh"

Terminal_output::Terminal_output() : curses(new Curses_wrapper) {

}

Terminal_output::Terminal_output(Curses_wrapper* curses) : curses(curses) {

}

void Terminal_output::print_line(std::string line) {
  curses->print(line.append("\n"));
}

void Terminal_output::refresh() {
  curses->refresh();
}
