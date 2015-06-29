#!/bin/sh

mkdir -p usr && mkdir -p usr/bin
git clone git://github.com/martine/ninja.git && cd ninja
git checkout release
python2 configure.py --bootstrap
mv ninja ../usr/bin/
