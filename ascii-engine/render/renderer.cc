#include <string>
#include "renderer.hh"

Renderer::Renderer(int width, int height) : width(width), height(height) {
  std::string empty_row(width, ' ');
  for (int i = 0; i < height; ++i) {
    char_matrix.push_back(empty_row);
  }
}

void Renderer::add(Renderable* renderable) {
  renderables.emplace_back(renderable);
}

void Renderer::render() {
  int x = renderables[0]->get_x();
  int y = renderables[0]->get_y();
  std::string str = renderables[0]->get_str();
  char_matrix[y].replace(x, str.length(), str);
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
  return char_matrix[0];
}

bool Renderer::char_matrix_is_empty() const {
  return char_matrix.empty();
}
