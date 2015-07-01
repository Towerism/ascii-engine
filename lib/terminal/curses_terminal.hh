#pragma once

#include <string>
#include "terminal_interface.hh"

class Curses_terminal : public Terminal_interface {
public:

  static Curses_terminal& get();

  virtual ~Curses_terminal();

  virtual void print(std::string str) override;
  virtual void refresh() override;

private:

  Curses_terminal();

  Curses_terminal(const Curses_terminal&) = delete;
  void operator=(const Curses_terminal&) = delete;

};
