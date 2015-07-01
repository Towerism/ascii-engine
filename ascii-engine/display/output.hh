#pragma once

#include <string>

class Output {
public:

  virtual void print_line(std::string line) = 0;
  virtual void refresh() = 0;

  virtual ~Output() { }
};
