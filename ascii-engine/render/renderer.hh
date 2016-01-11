//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <string>
#include <vector>
#include "renderable.hh"

class Renderer {
public:

  virtual void add(Renderable* renderable) = 0;
  virtual std::vector<std::string> render() = 0;

  virtual int get_width() const = 0;
  virtual int get_height() const = 0;
  virtual const Renderable* get_renderable(int index) const = 0;

  virtual ~Renderer() = default;

};
