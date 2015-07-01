#include <string>
#include <curses_wrapper.hh>
#include <terminal_interface.hh>
#include "terminal_output.hh"

Terminal_output::Terminal_output() : terminal(new Curses_wrapper) {

}

Terminal_output::Terminal_output(Terminal_interface* terminal) : terminal(terminal) {

}

void Terminal_output::print_line(std::string line) {
  terminal->print(line.append("\n"));
}

void Terminal_output::refresh() {
  terminal->refresh();
}
