# ASCII-Engine [![Build Status](https://travis-ci.org/Towerism/ascii-engine.svg?branch=develop)](https://travis-ci.org/Towerism/ascii-engine) [![Coverage Status](https://coveralls.io/repos/Towerism/ascii-engine/badge.svg?branch=develop)](https://coveralls.io/r/Towerism/ascii-engine?branch=develop)
An ascii-based text manipulation engine

## Requirements
* Linux or Mac OSX
* GCC 4.9+
* CMake 2.8.7+
* GNU Make 4.1+ or Ninja 1.5.3+
Windows is probably okay but technically not supported.

On another note, ninja is technically faster than make, but this won't be noticeable until the library gets bigger.

## Clone
```
$ git clone --recursive git@github.com:towerism/ascii-engine
$ cd ascii-engine
```

## Compile
```
$ make
```
or
```
$ ninja
```
Compiling with your project is easy, just hook up the main `CMakeLists.txt` with your own CMake build system.

## Testing
```
$ make test
```
or
```
$ ninja test
```

## Link with your project
In CMake link with `ascii-engine`. Otherwise, you can link with `-lascii-engine`.

