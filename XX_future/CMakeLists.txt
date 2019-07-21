project(future-test)

cmake_minimum_required(VERSION 3.2.2)

set(future-test-VERSION_MAJOR 1)
set(future-test-VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

# refenece pkg-config --libs --cflags
find_package(PkgConfig)

add_executable(mainbin ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(mainbin pthread)
