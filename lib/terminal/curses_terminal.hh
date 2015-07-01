#pragma once

#include <string>
#include "terminal.hh"

class Curses_terminal : public Terminal {
public:

  Curses_terminal();

  virtual void print(std::string str) override;
  virtual void refresh() override;

};
