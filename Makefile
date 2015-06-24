.PHONY:: all submodules submodules-init submoules-sync \
				generate test compile clean-build
.DEFAULT:: all

all::
	@echo "-- Starting Build"

#### Submodules

all submodules::
	@echo "-- Checking submodules..."
all submodules:: .touch-submodules
.touch-submodules:
	@printf -- "-- Updating submodules"
	@git submodule --quiet init
	@git submodule --quiet sync
	@git submodule --quiet update
	@touch .touch-submodules
	@printf " done\n"

#### CMake and Compiling

all generate::
	@mkdir -p build && cd build && cmake ..
all compile::
	@make -s -C build

#### Testing

all test:: generate compile
	@make test -s -C build

all::
	@echo "-- Done"

#### Cleaning

clean::
	@echo "-- Cleaning"
clean clean-build::
	@echo "-- Removing Build"
	@rm -rf build
clean::
	@echo "-- Done"
