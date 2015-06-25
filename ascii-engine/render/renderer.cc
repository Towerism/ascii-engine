#include <string>
#include <sstream>
#include "renderer.hh"

Renderer::Renderer(int width, int height) : width(width), height(height) {
  init_char_matrix(' ');
}

void Renderer::init_char_matrix(char value) {
  std::string empty_row(width, value);
  init_n_char_matrix_rows(height, empty_row);
}

void Renderer::init_n_char_matrix_rows(int n, std::string value) {
  for (int i = 0; i < n; ++i) {
    char_matrix.push_back(value);
  }
}

void Renderer::add(Renderable* renderable) {
  renderables.emplace_back(renderable);
}

void Renderer::render() {
  int x = renderables[0]->get_x();
  int y = renderables[0]->get_y();
  stream.str(renderables[0]->get_str());
  render_stream_to_char_matrix(x, y);
}

void Renderer::render_stream_to_char_matrix(int x, int y) {
  for (int i = y; stream.good(); ++i) {
    next_line_from_stream();
    render_line_to_char_matrix(x, i);
  }
}

void Renderer::next_line_from_stream() {
  getline(stream, line);
}

void Renderer::render_line_to_char_matrix(int x, int y) {
  char_matrix[y].replace(x, line.length(), line);
  char_matrix[y].erase(width, std::string::npos);
}

int Renderer::get_width() const {
  return width;
}

int Renderer::get_height() const {
  return height;
}

const Renderable* Renderer::get_renderable(int index) const {
  return renderables[index].get();
}

std::string Renderer::get_string_at_row(int index) const {
  return char_matrix[index];
}

bool Renderer::char_matrix_is_empty() const {
  return char_matrix.empty();
}
