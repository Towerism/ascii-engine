//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  AsciiEngine is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include<string>
#include<sstream>

class Line_extractor {
public:

  Line_extractor(std::string str = "");

  std::string next_line();

  void set_string(std::string str);

  bool there_are_more_lines();

private:

  std::istringstream stream;

  void ensure_stream_is_good();

};
