#pragma once

#include <string>

class Curses_wrapper {
public:
  Curses_wrapper();
  virtual ~Curses_wrapper();

  virtual void print(std::string str);
  virtual void refresh();
};
