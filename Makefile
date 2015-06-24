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

all test:: generate compile
	@make run-tests -s -C build

all::
	@echo "-- Done"

#### Coveralls

coveralls configure-coveralls::
	@mkdir -p build && cd build && cmake .. -DCMAKE_BUILD_TYPE=DEBUG -DENABLE_GCOV=1
coveralls build-coveralls:: compile

send-coveralls::
	@coveralls --exclude test --gcov-options '\-lp'

#### Cleaning

clean::
	@echo "-- Cleaning"
clean clean-build::
	@echo "-- Removing Build"
	@rm -rf build
clean::
	@echo "-- Done"
