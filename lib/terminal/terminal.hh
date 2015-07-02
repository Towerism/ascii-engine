#pragma once

#include <string>

class Terminal {
public:

  virtual void print(std::string str) = 0;
  virtual void refresh() = 0;
  virtual void clear() = 0;

  virtual ~Terminal() { }
};
