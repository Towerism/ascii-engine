#include <iostream>
#include <string>
#include <sstream>
#include "renderer.hh"

Renderer::Renderer(int width, int height) :
  width(width), height(height), char_matrix(width, height) {
}

void Renderer::add(Renderable* renderable) {
  renderables.emplace_back(renderable);
}

std::vector<std::string> Renderer::render() {
  for (auto renderable : renderables)
    render_renderable(renderable);
  return char_matrix.get_lines();
}

void Renderer::render_renderable(std::shared_ptr<Renderable> renderable) {
  int x = renderable->get_x();
  int y = renderable->get_y();
  std::string str = renderable->get_str();
  char_matrix.render_at(x, y, str);
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
