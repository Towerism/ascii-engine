#include <curses.h>
#include "curses_wrapper.hh"

Curses_wrapper::Curses_wrapper() {
  initscr();
}

Curses_wrapper::~Curses_wrapper() {
  endwin();
}

void Curses_wrapper::print(std::string str) {
  printw("%s", str.c_str());
}

void Curses_wrapper::refresh() {
  ::refresh();
}
