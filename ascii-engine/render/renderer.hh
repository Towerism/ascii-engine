#pragma once

#include <string>
#include <vector>
#include "renderable.hh"

class Renderer {
public:

  virtual void add(Renderable* renderable) = 0;
  virtual std::vector<std::string> render() = 0;

  virtual int get_width() const = 0;
  virtual int get_height() const = 0;
  virtual const Renderable* get_renderable(int index) const = 0;

  virtual ~Renderer() = default;

};
