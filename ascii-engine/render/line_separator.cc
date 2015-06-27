#include <string>
#include "line_separator.hh"

Line_separator::Line_separator(std::string str) : stream(str) {

}

std::string Line_separator::next_line() {
  std::string line;
  getline(stream, line);
  return line;
}

bool Line_separator::there_are_more_lines() {
  return !stream.eof();
}
