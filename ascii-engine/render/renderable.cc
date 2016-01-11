//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <string>
#include "renderable.hh"

Renderable::Renderable(int x, int y, std::string str) : x(x), y(y), str(str) {

}

int Renderable::get_x() const {
  return x;
}

int Renderable::get_y() const {
  return y;
}

const std::string& Renderable::get_str() const {
  return str;
}
