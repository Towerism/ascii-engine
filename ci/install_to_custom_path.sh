
# install lcov
git clone https://github.com/linux-test-project/lcov.git
make install PREFIX=. -s C lcov

# Create symlinks for new gcc binaries
ln -s $(which g++-5) usr/bin/g++
ln -s $(which gcc-5) usr/bin/gcc
ln -s $(which gcov-5) usr/bin/gcov

gem install coveralls-lcov
