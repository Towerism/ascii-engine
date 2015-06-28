CMAKE_FLAGS=


.PHONY:: all test cmake-test-flags run-tests \
         coverage cmake-coverage-flags build-coveralls \
         build-dir generate compile clean clean-build

.DEFAULT:: all
all:: test


test cmake-test-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=ON)
test run-tests:: generate compile
	@make run-tests -s -C build


coverage cmake-coverage-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=ON -DENABLE_COVERAGE=ON)
coverage build-coveralls:: generate compile
	@make coverage -s -C build


build-dir::
	@mkdir -p build
generate:: build-dir
	@cd build && cmake $(CMAKE_FLAGS) ..
compile::
	@make -s -C build


clean::
	@echo "-- Cleaning"
clean clean-build::
	@echo "-- Removing Build"
	@rm -rf build
clean::
	@echo "-- Done"
