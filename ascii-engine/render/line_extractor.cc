#include <string>
#include "line_extractor.hh"

Line_extractor::Line_extractor(std::string str) : stream(str) {

}

std::string Line_extractor::next_line() {
  std::string line;
  getline(stream, line);
  return line;
}

void Line_extractor::set_string(std::string str) {
  ensure_stream_is_good();
  stream.str(str);
}

void Line_extractor::ensure_stream_is_good() {
  stream.clear();
}

bool Line_extractor::there_are_more_lines() {
  return !stream.eof();
}
