#include "char_matrix.hh"
#include "line_separator.hh"

Char_matrix::Char_matrix(int width, int height) : width(width), height(height) {
  std::string empty_row(width, ' ');
  init_n_rows_with_value(height, empty_row);
}

void Char_matrix::init_n_rows_with_value(int n, std::string value) {
  for (int i = 0; i < n; ++i) {
    lines.push_back(value);
  }
}

void Char_matrix::render_at(int x, int y, std::string str) {
  Line_separator separator(str);
  for (int i = y; separator.there_are_more_lines(); ++i) {
    std::string line = separator.next_line();
    render_line_at(x, i, line);
  }
}

void Char_matrix::render_line_at(int x, int y, std::string line) {
  lines[y].replace(x, line.length(), line);
  trim_row(y);
}

void Char_matrix::trim_row(int index) {
  if (lines[index].length() >= width) {
    lines[index].erase(width, std::string::npos);
  }
}

std::string Char_matrix::get_line(int index) const {
  return lines[index];
}

bool Char_matrix::is_empty() const {
  return lines.empty();
}
