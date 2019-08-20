project(future-promise-errc-test)

cmake_minimum_required(VERSION 3.2.2)

set(future-promise-errc-test-VERSION_MAJOR 1)
set(future-promise-errc-test-VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# refenece pkg-config --libs --cflags
find_package(PkgConfig)
pkg_check_modules(LIBI18N REQUIRED icu-i18n)
include_directories(${LIBI18N_INCLUDE_DIRS})
link_directories(${LIBI18N_LIBRARY_DIRS})

link_directories(${PROJECT_SOURCE_DIR}/../../../tool/libs)
include_directories(mytime ${PROJECT_SOURCE_DIR}/../../../tool/include)
add_executable(mainbin ${PROJECT_SOURCE_DIR}/src/main.cpp)
#target_link_libraries(mainbin mytime ${LIBI18N_LIBRARY_DIRS})
install(TARGETS mainbin
        RUNTIME DESTINATION ./bin)