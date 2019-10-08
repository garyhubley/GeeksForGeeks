

CC=g++
CXXFLAGS=-Wall 

all: MinHeapAmazon.o
	$(CC) $(CXXFLAGS) $< -o minheapamazon

.cpp.o: MinHeapAmazon.cpp
	$(CC) $(CXXFLAGS) -c $*.cpp

clean:
	rm -rf *.o minheapamazon
