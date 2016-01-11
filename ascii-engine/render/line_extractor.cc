//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
