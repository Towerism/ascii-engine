//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <string>

class Terminal {
public:

  virtual void print(std::string str) = 0;
  virtual void refresh() = 0;
  virtual void clear() = 0;

  virtual ~Terminal() = default;
};
