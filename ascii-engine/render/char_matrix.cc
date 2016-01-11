//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "char_matrix.hh"
#include "line_extractor.hh"

Char_matrix::Char_matrix(int width, int height) : width(width), height(height) {
  std::string empty_row(width, ' ');
  init_n_rows_with_value(height, empty_row);
}

void Char_matrix::init_n_rows_with_value(int n, std::string& value) {
  for (int i = 0; i < n; ++i)
    lines.push_back(value);
}

void Char_matrix::render_at(int x, int y, std::string str) {
  extractor.set_string(str);
  render_lines_at(x, y);
}

void Char_matrix::render_lines_at(int x, int y) {
  for (int i = y; extractor.there_are_more_lines(); ++i)
    render_next_line_at(x, i);
}

void Char_matrix::render_next_line_at(int x, int y) {
  std::string line = extractor.next_line();
  lines[y].replace(x, line.length(), line);
  trim_row(y);
}

void Char_matrix::trim_row(int index) {
  if (lines[index].length() >= width)
    lines[index].erase(width, std::string::npos);
}

std::vector<std::string> Char_matrix::get_lines() const {
  return lines;
}
