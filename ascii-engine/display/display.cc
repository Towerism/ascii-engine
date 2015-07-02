#include <vector>
#include <string>
#include <ascii-engine/render/renderer.hh>
#include <terminal.hh>
#include "display.hh"

Display::Display(Renderer* renderer, Terminal* terminal) : renderer(renderer), terminal(terminal) {

}

void Display::update() {
  std::vector<std::string> lines_rendered = renderer->render();
  print_lines(lines_rendered);
  update_terminal();
}

void Display::print_lines(const std::vector<std::string>& lines) {
  for (auto line : lines)
    print_line_appended_with(line, "\n");
}

void Display::print_line_appended_with(const std::string& line, const std::string& append) {
  std::string appended_line = line + append;
  terminal->print(appended_line);
}

void Display::update_terminal() {
  terminal->refresh();
  terminal->clear();
}
