#include <vector>
#include <string>
#include <ascii-engine/render/renderer.hh>
#include <terminal.hh>
#include "display.hh"

Display::Display(Renderer* renderer, Terminal* terminal) : renderer(renderer), terminal(terminal) {

}

void Display::update() {
  std::vector<std::string> lines_rendered = renderer->render();
  for (auto line : lines_rendered)
    terminal->print(line.append("\n"));
  terminal->refresh();
}
