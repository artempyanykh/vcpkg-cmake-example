.PHONY: bootstrap
bootstrap:
	git submodule update --init && vcpkg/bootstrap-vcpkg.sh

.PHONY: clean
clean:
	rm -rf build

.PHONY: configure
configure:
	cmake -S . -B build -G Ninja

.PHONY: build
build:
	cmake --build build

.PHONY: run
run: build
	build/main

.PHONY: reconfigure
reconfigure: clean configure