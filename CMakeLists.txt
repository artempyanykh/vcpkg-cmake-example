cmake_minimum_required(VERSION 3.22)

set(VCPKG_ROOT "vcpkg")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(EX VERSION 0.0.1)

find_package(fmt CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

add_executable(main main.cpp)
target_compile_features(main PUBLIC cxx_std_20)
target_link_libraries(main PRIVATE fmt::fmt CLI11::CLI11)

