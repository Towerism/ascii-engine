//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <curses.h>
#include "curses_terminal.hh"

Curses_terminal::Curses_terminal() {
  initscr();
}

Curses_terminal::~Curses_terminal() {
  endwin();
}

void Curses_terminal::print(std::string str) {
  printw("%s", str.c_str());
}

void Curses_terminal::refresh() {
  ::refresh();
}

void Curses_terminal::clear() {
  ::clear();
}
