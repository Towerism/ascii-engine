[![Build Status](https://travis-ci.org/Towerism/ascii-engine.svg?branch=build)](https://travis-ci.org/Towerism/ascii-engine)

# ASCII-Engine
An ascii-based text manipulation engine

## Requirements
* GCC 4.9+
* CMake 2.8.7+
* GNU Make 4.1+

## Clone
```
$ git clone git@github.com:towerism/ascii-engine
$ cd ascii-engine
```

## Compile
```
$ make
```
Compiling with your project is easy, just hook up the main `CMakeLists.txt` with your own CMake build system.

## Testing
```
$ make test
```

## Link with your project
In CMake link with `ascii-engine`. Otherwise, you can link with `-lascii-engine`.

