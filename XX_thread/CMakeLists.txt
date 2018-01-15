project(thread-test)

#cmake_minimum_required(VERSION 3.5.1)

set(thread-test-VERSION_MAJOR 1)
set(thread-test-VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_BINARY_DIR}/include")

find_package(Threads)

add_executable(mainbin ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(mainbin ${CMAKE_THREAD_LIBS_INIT})
