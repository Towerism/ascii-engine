#pragma once

#include <string>
#include <sstream>
#include <vector>

class Char_matrix {
public:

  Char_matrix(int width = 0, int height = 0);

  void render_at(int x, int y, std::string str);

  std::string string_at_row(int index) const;
  bool is_empty() const;

private:

  int width, height;

  std::vector<std::string> strings;
  std::istringstream stream;

  void init_n_rows_with_value(int n, std::string value);
  void prepare_stream(std::string str);
  void render_stream_at(int x, int y);
  void make_stream_good();
  std::string next_line();
  void render_line(int x, int y, std::string line);

};
