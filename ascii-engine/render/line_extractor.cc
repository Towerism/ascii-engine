#include <string>
#include "line_extractor.hh"

Line_extractor::Line_extractor(std::string str) : stream(str) {

}

std::string Line_extractor::next_line() {
  std::string line;
  getline(stream, line);
  return line;
}

bool Line_extractor::there_are_more_lines() {
  return !stream.eof();
}
