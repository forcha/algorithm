CXXFLAGS=-std=c++11

BINARIES=quickfind dijkstra2stack selectionsort insertionsort

all: ${BINARIES}

.PHONY: clean

clean:
	rm ${BINARIES}

quickfind: quickfind.cpp

dijkstra2stack: dijkstra2stack.cpp

selectionsort: selectionsort.cpp

insertionsort: insertionsort.cpp
