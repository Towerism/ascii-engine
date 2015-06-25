#include "char_matrix.hh"

Char_matrix::Char_matrix(int width, int height) : width(width), height(height) {
  std::string empty_row(width, ' ');
  init_n_rows_with_value(height, empty_row);
}

void Char_matrix::init_n_rows_with_value(int n, std::string value) {
  for (int i = 0; i < n; ++i) {
    strings.push_back(value);
  }
}

void Char_matrix::render_at(int x, int y, std::string str) {
  prepare_stream(str);
  render_stream_at(x, y);
  make_stream_good();
}

void Char_matrix::prepare_stream(std::string str) {
  stream.str(str);
}

void Char_matrix::render_stream_at(int x, int y) {
  for (int i = y; stream.good(); ++i) {
    std::string line = next_line();
    render_line(x, i, line);
  }
}

void Char_matrix::make_stream_good() {
  stream.clear();
}

std::string Char_matrix::next_line() {
  std::string line;
  getline(stream, line);
  return line;
}

void Char_matrix::render_line(int x, int y, std::string line) {
  strings[y].replace(x, line.length(), line);
  if (strings[y].length() >= width) {
    strings[y].erase(width, std::string::npos);
  }
}

std::string Char_matrix::string_at_row(int index) const {
  return strings[index];
}

bool Char_matrix::is_empty() const {
  return strings.empty();
}
