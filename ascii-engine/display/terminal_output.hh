#pragma once

#include <memory>
#include <string>
#include <curses_terminal.hh>
#include <terminal.hh>

class Terminal_output {
public:

  Terminal_output(Terminal* terminal = new Curses_terminal);

  void print_line(std::string line);
  void refresh();

private:

  std::unique_ptr<Terminal> terminal;

};
