#pragma once

#include<string>
#include<sstream>

class Line_extractor {
public:

  Line_extractor(std::string str);

  std::string next_line();

  bool there_are_more_lines();

private:

  std::istringstream stream;

};
