#pragma once

#include <memory>
#include <string>
#include <curses_wrapper.hh>

class Terminal_output {
public:

  Terminal_output(Curses_wrapper* curses);

  void print_line(std::string line);

private:

  std::unique_ptr<Curses_wrapper> curses;

};
