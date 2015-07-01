#pragma once

#include <string>

class Terminal_interface {
public:

  virtual void print(std::string str) = 0;
  virtual void refresh() = 0;

  virtual ~Terminal_interface() { }
};
