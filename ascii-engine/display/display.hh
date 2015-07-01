#pragma once

#include <memory>
#include <ascii-engine/render/renderer.hh>
#include "output.hh"

class Display {
public:

  Display(Renderer* renderer, Output* output);

  void update();

private:

  std::unique_ptr<Renderer> renderer;
  std::unique_ptr<Output> output;
};
