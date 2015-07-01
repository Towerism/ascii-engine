#pragma once

#include <ascii-engine/render/renderer.hh>
#include "output.hh"

class Display {
public:

  Display(Renderer* renderer, Output* output);

  void update();
};
