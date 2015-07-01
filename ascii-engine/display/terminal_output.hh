#pragma once

#include <memory>
#include <string>
#include <curses_terminal.hh>
#include <terminal.hh>
#include "output.hh"

class Terminal_output : Output {
public:

  Terminal_output(Terminal* terminal);

  virtual void print_line(std::string line) override;
  virtual void refresh() override;

private:

  std::unique_ptr<Terminal> terminal;

};
