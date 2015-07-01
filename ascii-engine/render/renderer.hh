#pragma once

#include <memory>
#include <sstream>
#include <vector>
#include "char_matrix.hh"
#include "renderable.hh"

class Renderer {
public:

  Renderer(int width = 0, int height = 0);

  void add(Renderable* renderable);
  virtual std::vector<std::string> render();

  int get_width() const;
  int get_height() const;
  const Renderable* get_renderable(int index) const;

  virtual ~Renderer();

private:

  int width, height;
  std::vector<std::shared_ptr<Renderable>> renderables;
  Char_matrix char_matrix;

  void render_to_matrix();
  void render_renderable(std::shared_ptr<Renderable> renderable);
};
