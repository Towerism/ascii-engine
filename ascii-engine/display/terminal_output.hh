#pragma once

#include <memory>
#include <string>
#include <terminal_interface.hh>

class Terminal_output {
public:

  Terminal_output();
  Terminal_output(Terminal_interface* terminal);

  void print_line(std::string line);
  void refresh();

private:

  std::unique_ptr<Terminal_interface> terminal;

};
