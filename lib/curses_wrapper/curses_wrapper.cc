#include <curses.h>
#include "curses_wrapper.hh"

Curses_wrapper::Curses_wrapper() {

}

Curses_wrapper::~Curses_wrapper() {

}

void Curses_wrapper::print(std::string str) {
  printw("%s", str.c_str());
}
