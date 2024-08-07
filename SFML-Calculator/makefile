
# optional flags (if the compiler supports it)
# CXXFLAGS += -std=c++11

# HIGHLY RECOMMENDED flags
CXXFLAGS += -Wall -Wextra -pedantic-errors

# required for SFML programs
LDLIBS := $(shell pkg-config sfml-all --libs)

# The rest will turn any source file ending in .cpp
# into a program of the same name

all: object compile run

object: 
	g++ -c *.cpp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

compile:
	g++ *.o -o program -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

run: 
	./program
