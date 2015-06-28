#pragma once

#include <string>
#include <vector>
#include "line_extractor.hh"

class Char_matrix {
public:

  Char_matrix(int width = 0, int height = 0);

  void render_at(int x, int y, std::string str);

  std::string get_line(int index) const;
  bool is_empty() const;

private:

  int width, height;

  std::vector<std::string> lines;

  void init_n_rows_with_value(int n, std::string value);
  void render_lines_at(int x, int y, Line_extractor& extractor);
  void render_line_at(int x, int y, std::string line);
  void trim_row(int index);

};
