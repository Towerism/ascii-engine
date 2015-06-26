.PHONY:: all generate compile test clean-build
.DEFAULT:: all

CMAKE_FLAGS=

all::
	@echo "-- Starting Build"

#### CMake and Compiling

all build-dir::
	@mkdir -p build
all generate:: build-dir
	@cd build && cmake $(CMAKE_FLAGS) ..
all compile::
	@make -s -C build

all::
	@echo "-- Done"

#### Testing

test cmake-test-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=1)
test run-tests:: generate compile
	@make run-tests -s -C build

#### Coveralls

coverage cmake-coverage-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=1 -DENABLE_COVERAGE=1)
coverage build-coveralls:: generate compile
	@make coverage -s -C build

#### Cleaning

clean::
	@echo "-- Cleaning"
clean clean-build::
	@echo "-- Removing Build"
	@rm -rf build
clean::
	@echo "-- Done"
