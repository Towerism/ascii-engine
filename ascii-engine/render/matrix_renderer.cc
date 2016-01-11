//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <iostream>
#include <string>
#include <sstream>
#include "matrix_renderer.hh"

Matrix_renderer::Matrix_renderer(int width, int height) :
  width(width), height(height), char_matrix(width, height) {
}

void Matrix_renderer::add(Renderable* renderable) {
  renderables.emplace_back(renderable);
}

std::vector<std::string> Matrix_renderer::render() {
  for (auto renderable : renderables)
    render_renderable(renderable);
  return char_matrix.get_lines();
}

void Matrix_renderer::render_renderable(std::shared_ptr<Renderable> renderable) {
  int x = renderable->get_x();
  int y = renderable->get_y();
  std::string str = renderable->get_str();
  char_matrix.render_at(x, y, str);
}

int Matrix_renderer::get_width() const {
  return width;
}

int Matrix_renderer::get_height() const {
  return height;
}

const Renderable* Matrix_renderer::get_renderable(int index) const {
  return renderables[index].get();
}
