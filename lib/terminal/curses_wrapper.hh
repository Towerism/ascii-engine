#pragma once

#include <string>
#include "terminal_interface.hh"

class Curses_wrapper : public Terminal_interface {
public:
  Curses_wrapper();
  virtual ~Curses_wrapper();

  virtual void print(std::string str) override;
  virtual void refresh() override;
};
