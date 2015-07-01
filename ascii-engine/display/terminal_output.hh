#pragma once

#include <memory>
#include <string>
#include <curses_terminal.hh>
#include <terminal_interface.hh>

class Terminal_output {
public:

  Terminal_output(Terminal_interface* terminal = &Curses_terminal::get());

  void print_line(std::string line);
  void refresh();

private:

  Terminal_interface* terminal;

};
