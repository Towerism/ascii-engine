#pragma once

#include <memory>
#include <sstream>
#include <vector>
#include "char_matrix.hh"
#include "renderable.hh"
#include "renderer.hh"

class Matrix_renderer : Renderer {
public:

  Matrix_renderer(int width = 0, int height = 0);

  virtual void add(Renderable* renderable) override;
  virtual std::vector<std::string> render() override;

  virtual int get_width() const;
  virtual int get_height() const;
  virtual const Renderable* get_renderable(int index) const;

private:

  int width, height;
  std::vector<std::shared_ptr<Renderable>> renderables;
  Char_matrix char_matrix;

  void render_to_matrix();
  void render_renderable(std::shared_ptr<Renderable> renderable);
};
