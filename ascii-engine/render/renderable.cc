#include <string>
#include "renderable.hh"

Renderable::Renderable(int x, int y, std::string str) : x(x), y(y), str(str) {

}

int Renderable::get_x() const {
  return x;
}

int Renderable::get_y() const {
  return y;
}

const std::string& Renderable::get_str() const {
  return str;
}
