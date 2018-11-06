project(thread-test)

cmake_minimum_required(VERSION 3.2)

set(thread-test-VERSION_MAJOR 1)
set(thread-test-VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_BINARY_DIR}/include")

find_package(Threads)

add_executable(mainbin ${PROJECT_SOURCE_DIR}/src/main.cpp)
add_executable(2mainbin ${PROJECT_SOURCE_DIR}/src/mutex.cpp)
add_executable(3mainbin ${PROJECT_SOURCE_DIR}/src/cond.cpp)
target_link_libraries(mainbin ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(2mainbin ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(3mainbin ${CMAKE_THREAD_LIBS_INIT})
