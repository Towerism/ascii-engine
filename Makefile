CMAKE_FLAGS=


.PHONY:: all test cmake-test-flags run-tests \
         coverage cmake-coverage-flags build-coveralls \
         compile build-dir generate clean clean-build

.DEFAULT:: all
all:: test


test cmake-test-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=ON)
test run-tests:: compile
	@make run-tests/fast -s -C build


coverage cmake-coverage-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=ON -DENABLE_COVERAGE=ON)
coverage build-coveralls:: compile
	@make coverage/fast -s -C build


compile generate build-dir::
	@mkdir -p build
compile generate::
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
