# ASCII-Engine [![Build Status](https://travis-ci.org/Towerism/ascii-engine.svg?branch=develop)](https://travis-ci.org/Towerism/ascii-engine) [![Coverage Status](https://coveralls.io/repos/Towerism/ascii-engine/badge.svg?branch=develop)](https://coveralls.io/r/Towerism/ascii-engine?branch=develop)
An ascii-based text manipulation engine

## Requirements
* Linux or Mac OSX
* GCC 4.9+
* CMake 2.8.7+
* GNU Make 4.1+ or [Ninja](http://martine.github.io/ninja/) 1.5.3+

Windows is probably okay but technically not supported.

## Clone
```
$ git clone --recursive git://github.com/towerism/ascii-engine.git
$ cd ascii-engine
```
Also feel free to fork this repository to make your own changes.
## Compile
Two different build systems are supported:

*`make`
*`ninja`

Both are generated using CMake, and there are automated front ends for each CMake generator.
Simply use `$ make` or `$ ninja` to use the respective front end.  Or if you prefer to use
the `make` frontend and still use `ninja`, you can apply the following patch:
`$ git apply makefile-use-ninja.patch`.  Then `$ make` will generate the `ninja` build system.

Compiling with your project is easy, just hook up the main `CMakeLists.txt` with your own CMake build system.

As far as using `make` or `ninja`, it doesn't really matter if you just want to use the ASCII-Engine library.  But if you plan on contributing and doing incremental builds, then you will probably want to use `ninja`, especially as the library gets the larger.

## Testing
`$ make test` or `$ ninja test`

## Link with your project
In CMake link with `ascii-engine`. Otherwise, you can link with `-lascii-engine`.

