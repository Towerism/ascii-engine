#pragma once

#include <string>

class Renderable {
public:

  Renderable(int x = 0, int y = 0, std::string str = "");

  int get_x() const;
  int get_y() const;
  const std::string& get_str() const;

private:

  int x, y;
  std::string str;
};
