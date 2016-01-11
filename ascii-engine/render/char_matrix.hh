//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <string>
#include <vector>
#include "line_extractor.hh"

class Char_matrix {
public:

  Char_matrix(int width = 0, int height = 0);

  void render_at(int x, int y, std::string str);

  std::vector<std::string> get_lines() const;

private:

  int width, height;

  std::vector<std::string> lines;
  Line_extractor extractor;

  void init_n_rows_with_value(int n, std::string& value);
  void render_lines_at(int x, int y);
  void render_next_line_at(int x, int y);
  void trim_row(int index);

};
