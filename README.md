# C++ with cmake and vcpkg

An example project that demonstrates a setup using CMake + vcpkg for a
reasonable build with reasonable dependency management:
1. `CMakeLists.txt` contains a project definition and `vcpkg` integration bits.
2. `vcpkg.json` is a manifest file that defines a list of project dependencies.
3. `vcpkg` itself is checked-out as a submodule, so don' forget to run:
   1. `git submodule update --init`.
   2. `vcpkg/bootstrap-vcpkg.sh`.

* How to setup the build: `cmake -S . -B build [-G Ninja]`
* How to build the binary: `cmake --build build`
* How to run the built binary: run `build/main`

The top-level `Makefile` defines a number of phony targets that act as shortcuts for specific cmake invocations:
* `bootstrap` sets up `vcpkg`.
* `configure/reconfigure` prepare cmake build.
* `build/run` to compile and run the binary.
* `clean`.