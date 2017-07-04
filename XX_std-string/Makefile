SRC=01.cpp 02.cpp
CPPFLAGS=-std=c++11 -g


all: .cpp.o

.cpp.o:
	g++ $(CPPFLAGS) $< -o $(subst .cpp,.bin,$(SRC))
