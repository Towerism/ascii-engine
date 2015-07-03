#pragma once

#include <memory>
#include <ascii-engine/render/renderer.hh>
#include <terminal.hh>

class Display {
public:

  Display(std::shared_ptr<Renderer> renderer,
          std::shared_ptr<Terminal> terminal);

  void update();

private:

  std::shared_ptr<Renderer> renderer;
  std::shared_ptr<Terminal> terminal;

  void print_lines(const std::vector<std::string>& lines);
  void print_line_appended_with(const std::string& line, const std::string& append);
  void update_terminal();
};
