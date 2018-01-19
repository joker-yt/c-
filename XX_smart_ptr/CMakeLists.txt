project(smartptr-test)

#cmake_minimum_required(VERSION 3.2.2)

set(smartptr-test-VERSION_MAJOR 1)
set(smartptr-test-VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_BINARY_DIR}/include")

add_executable(mainbin ${PROJECT_SOURCE_DIR}/src/unique_ptr.cpp)
