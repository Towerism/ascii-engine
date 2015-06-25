#include <string>
#include <sstream>
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

  std::istringstream str_stream(str);
  for (int i = y; str_stream.good(); ++i) {
    std::string line;
    getline(str_stream, line);
    char_matrix[i].replace(x, line.length(), line);
    char_matrix[i].erase(width, std::string::npos);
  }
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
