
# optional flags (if the compiler supports it)
# CXXFLAGS += -std=c++11

# HIGHLY RECOMMENDED flags
CXXFLAGS += -Wall -Wextra -pedantic-errors

# required for SFML programs
LDLIBS := $(shell pkg-config sfml-all --libs)

# The rest will turn any source file ending in .cpp
# into a program of the same name

all: compile run

compile: 
	g++ $(CXXFLAGS) *.cpp $(LDLIBS) -o program

run: 
	./program
