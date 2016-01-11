//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <string>
#include "terminal.hh"

class Curses_terminal : public Terminal {
public:

  Curses_terminal();
  ~Curses_terminal();

  void print(std::string str) override;
  void refresh() override;
  void clear() override;

};
