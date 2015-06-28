CMAKE_FLAGS=

PROJECT_NAME=ASCII-Engine Library


.PHONY:: all test cmake-test-flags run-tests \
         coverage cmake-coverage-flags build-coveralls \
         compile build-dir generate clean clean-build

.DEFAULT:: all
all:: ##same as test
all:: test


test:: ##compile and run test suite
test cmake-test-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=ON)
test run-tests:: compile
	@make run-tests/fast -s -C build


coverage:: ##generate coverage analysis
coverage cmake-coverage-flags::
	$(eval CMAKE_FLAGS := -DENABLE_TESTING=ON -DENABLE_COVERAGE=ON)
coverage build-coveralls:: compile
	@make coverage/fast -s -C build


compile:: ##just compile
compile generate build-dir::
	@mkdir -p build
compile generate::
	@cd build && cmake $(CMAKE_FLAGS) ..
compile::
	@make -s -C build


clean:: ##clean build system
	@echo "-- Cleaning"
clean clean-build::
	@echo "-- Removing Build"
	@rm -rf build
clean::
	@echo "-- Done"


help:: ##show this help
	@echo "The following are some of the valid targets for this Makefile:"
help display-doublehash-help-comments::
	@sed -n '/##/p' $(MAKEFILE_LIST) \
   | sed -e '/sed/d' -e 's/##//' -e 's/^/\.\.\. /' -e 's/ /+/g' -e 's/::/ +-/g' \
   | column -t -s " " | sed 's/+/ /g'
