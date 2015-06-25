#include "renderer.hh"

Renderer::Renderer(int width, int height) : width(width), height(height) {

}

void Renderer::add(Renderable* renderable) {
  renderables.emplace_back(renderable);
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
