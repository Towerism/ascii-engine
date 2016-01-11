//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <string>

class Renderable {
public:

  Renderable(int x = 0, int y = 0, std::string str = "");

  int get_x() const;
  int get_y() const;
  const std::string& get_str() const;

private:

  int x, y;
  std::string str;
};
