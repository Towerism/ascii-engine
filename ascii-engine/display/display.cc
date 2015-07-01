#include <vector>
#include <string>
#include <ascii-engine/render/renderer.hh>
#include "display.hh"
#include "output.hh"

Display::Display(Renderer* renderer, Output* output) : renderer(renderer), output(output) {

}

void Display::update() {
  std::vector<std::string> rendered = renderer->render();
  for (auto line : rendered) {
    output->print_line(line);
  }
  output->refresh();
}
