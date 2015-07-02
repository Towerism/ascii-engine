#include <string>
#include <curses_terminal.hh>
#include <terminal.hh>
#include "terminal_output.hh"

Terminal_output::Terminal_output(Terminal* terminal) : terminal(terminal) {

}

void Terminal_output::print_line(std::string line) {
  terminal->print(line.append("\n"));
}

void Terminal_output::refresh() {
  terminal->refresh();
}
