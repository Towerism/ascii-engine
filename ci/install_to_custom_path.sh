if [ ! -z $PREFIX ]; then
  INSTALL_PREFIX=$PWD
else
  INSTALL_PREFIX=$PREFIX
fi

# install lcov
git clone https://github.com/linux-test-project/lcov.git
mkdir -p installed && cd lcov && make install PREFIX=${INSTALL_PREFIX} && cd ..

# Create symlinks for new gcc binaries
ln -s $(which g++-5) ${INSTALL_PREFIX}/usr/bin/g++
ln -s $(which gcc-5) ${INSTALL_PREFIX}/usr/bin/gcc
ln -s $(which gcov-5) ${INSTALL_PREFIX}/usr/bin/gcov

gem install coveralls-lcov
