#include <string>
#include "renderable.hh"

Renderable::Renderable() {

}

Renderable::Renderable(int x, int y, std::string str) {

}

int Renderable::get_x() const {
  return 123;
}

int Renderable::get_y() const {
  return 321;
}

const std::string& Renderable::get_str() const {
  return "stub return";
}
