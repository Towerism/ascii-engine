#!/bin/sh

# Create symlinks for gcc-5 binaries
ln -s $(which g++-5) usr/bin/g++
ln -s $(which gcc-5) usr/bin/gcc
ln -s $(which gcov-5) usr/bin/gcov
