# ASCII-Engine [![Build Status](https://travis-ci.org/Towerism/ascii-engine.svg?branch=develop)](https://travis-ci.org/Towerism/ascii-engine) [![Coverage Status](https://coveralls.io/repos/Towerism/ascii-engine/badge.svg?branch=develop)](https://coveralls.io/r/Towerism/ascii-engine?branch=develop)
An ascii-based text manipulation engine

## Requirements
* Linux or Mac OSX
* GCC 4.9+
* CMake 2.8.7+
* GNU Make 4.1+ or Ninja 1.5.3+
Windows is probably okay but technically not supported.

## Clone
```
$ git clone --recursive git@github.com:towerism/ascii-engine
$ cd ascii-engine
```
## Compile
`$ make` or `$ ninja`

Compiling with your project is easy, just hook up the main `CMakeLists.txt` with your own CMake build system.

As far as using `make` or `ninja`, it doesn't really matter if you just want to use the ASCII-Engine library.  But if you plan on contributing and doing incremental builds, then you will probably want to use `ninja`, especially as the library gets the larger.

## Testing
`$ make test` or `$ ninja test`

## Link with your project
In CMake link with `ascii-engine`. Otherwise, you can link with `-lascii-engine`.

