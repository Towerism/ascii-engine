#!/bin/sh

# Add ppa's
add-apt-repository -y ppa:ubuntu-toolchain-r/test
add-apt-repository -y ppa:george-edison55/cmake-3.x
apt-get update -qq

# install gcc5
apt-get install g++-5
apt-get install gcc-5

ln -sf /usr/bin/g++-5 /usr/bin/g++
ln -sf /usr/bin/gcc-5 /usr/bin/gcc
ln -sf /usr/bin/gcov-5 /usr/bin/gcov

# install lcov
wget http://launchpadlibrarian.net/178468692/lcov_1.11-2_all.deb
dpkg -i lcov_1.11-2_all.deb

# install ninja
if [ "$BUILD_SYSTEM" == "ninja" ]; then
  mkdir -p usr && mkdir -p usr/bin
  git clone git://github.com/martine/ninja.git && cd ninja
  git checkout release
  python2 configure.py --bootstrap
  mv ninja /usr/bin/
  cd ..
fi

# install cmake
sudo apt-get install cmake

# install coveralls-lcov
gem install coveralls-lcov
