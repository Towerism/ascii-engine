#include "renderer.hh"

Renderer::Renderer(int width, int height) : width(width), height(height) {

}

int Renderer::get_width() {
  return width;
}

int Renderer::get_height() {
  return height;
}
