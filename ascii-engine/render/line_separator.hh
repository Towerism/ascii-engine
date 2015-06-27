#pragma once

#include<string>
#include<sstream>

class Line_separator {
public:

  Line_separator(std::string str);

  std::string next_line();

  bool there_are_more_lines();

private:

  std::istringstream stream;

};
