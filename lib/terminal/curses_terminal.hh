#pragma once

#include <string>
#include "terminal_interface.hh"

class Curses_terminal : public Terminal_interface {
public:
  Curses_terminal();
  virtual ~Curses_terminal();

  virtual void print(std::string str) override;
  virtual void refresh() override;
};
