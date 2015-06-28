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
