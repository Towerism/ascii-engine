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
