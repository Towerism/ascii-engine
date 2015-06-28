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
  void render();
  std::vector<std::string> display() const;

  int get_width() const;
  int get_height() const;
  const Renderable* get_renderable(int index) const;
  std::string get_line(int index) const;
  bool char_matrix_is_empty() const;

private:

  int width, height;
  std::vector<std::shared_ptr<Renderable>> renderables;
  Char_matrix char_matrix;

  void render_renderable(std::shared_ptr<Renderable> renderable);
};
