//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
