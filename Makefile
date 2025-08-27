configure:
	@conan install . --output-folder=build --build=missing
	@cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
                -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
                -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake

build:
	@cmake --build build --config Release

check:
	@clang-tidy src/*.cpp -- -Iinclude

test:
	check
	@ctest --test-dir build --output-on-failure

run:
	@build/bloxoff_engine

all:
	configure
	build
	run
