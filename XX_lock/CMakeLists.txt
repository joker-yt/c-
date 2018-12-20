project(lock-test)

cmake_minimum_required(VERSION 3.2.2)

set(lock-test-VERSION_MAJOR 1)
set(lock-test-VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

add_executable(ex1.out ${PROJECT_SOURCE_DIR}/src/ex1.cpp)
target_link_libraries(ex1.out pthread)

add_executable(ex2.out ${PROJECT_SOURCE_DIR}/src/ex2.cpp)
target_link_libraries(ex2.out pthread)

add_executable(ex3.out ${PROJECT_SOURCE_DIR}/src/ex3.cpp)
target_link_libraries(ex3.out pthread)
