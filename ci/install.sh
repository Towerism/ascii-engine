#!/bin/sh

# install cov
git clone https://github.com/linux-test-project/lcov.git
mkdir -p installed && cd lcov && make install PREFIX=.. && cd ..

# Create symlinks for gcc-5 binaries
ln -s $(which g++-5) usr/bin/g++
ln -s $(which gcc-5) usr/bin/gcc
ln -s $(which gcov-5) usr/bin/gcov

gem install coveralls-lcov

# Update path in profile
echo "export PATH=$PWD/usr/bin/:$PATH" >> ~/.profile
source ~/.profile
