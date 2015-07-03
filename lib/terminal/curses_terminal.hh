#pragma once

#include <string>
#include "terminal.hh"

class Curses_terminal : public Terminal {
public:

  Curses_terminal();
  ~Curses_terminal();

  void print(std::string str) override;
  void refresh() override;
  void clear() override;

};
