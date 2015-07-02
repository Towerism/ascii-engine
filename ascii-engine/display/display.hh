#pragma once

#include <memory>
#include <ascii-engine/render/renderer.hh>
#include <terminal.hh>

class Display {
public:

  Display(Renderer* renderer, Terminal* );

  void update();

private:

  std::unique_ptr<Renderer> renderer;
  std::unique_ptr<Terminal> terminal;

  void print_lines(const std::vector<std::string>& lines);
  void print_line_appended_with(const std::string& line, const std::string& append);
};
