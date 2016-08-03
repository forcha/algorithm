CXXFLAGS=-std=c++11 -g

BINARIES=quickfind dijkstra2stack selectionsort insertionsort quicksort

all: ${BINARIES}

.PHONY: clean

clean:
	rm ${BINARIES}

quickfind: quickfind.cpp

dijkstra2stack: dijkstra2stack.cpp

selectionsort: selectionsort.cpp

insertionsort: insertionsort.cpp

quicksort: quicksort.cpp
