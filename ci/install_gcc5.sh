#!/bin/sh

add-apt-repository ppa:ubuntu-toolchain-r/test -y
apt-get update -qq

apt-get install g++-5
apt-get install gcc-5

ln -sf /usr/bin/g++-5 /usr/bin/g++
ln -sf /usr/bin/gcc-5 /usr/bin/gcc
ln -sf /usr/bin/gcov-5 /usr/bin/gcov
