.PHONY:: all generate compile test clean-build
.DEFAULT:: all

all::
	@echo "-- Starting Build"

#### CMake and Compiling

all generate::
	@mkdir -p build && cd build && cmake ..
all compile::
	@make -s -C build

#### Testing

all test pre-test:: generate compile
all test run-tests::
	@make run-tests -s -C build

all::
	@echo "-- Done"

#### Coveralls

coveralls configure-coveralls::
	@mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=DEBUG -DENABLE_COVERAGE=1 ..
coveralls build-coveralls:: compile
	@make coverage -s -C build

send-coveralls::
	@cd build && coveralls-lcov --exclude test --gcov-options '\-lp'

#### Cleaning

clean::
	@echo "-- Cleaning"
clean clean-build::
	@echo "-- Removing Build"
	@rm -rf build
clean::
	@echo "-- Done"
