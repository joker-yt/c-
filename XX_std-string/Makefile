SRC=01.cpp 02.cpp
EXE=$(subst .cpp,.bin,$(SRC))
CPPFLAGS=-std=c++11 -g

all: $(EXE)

.SUFFIXES:	.cpp .bin
.cpp.bin:
	g++ $(CPPFLAGS) $< -o $@

clean:
	rm *.bin
