CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: driver

simplecanvas.o: simplecanvas/simplecanvas.h simplecanvas/simplecanvas.cpp
	$(CC) $(CFLAGS) -c simplecanvas/simplecanvas.cpp

shapes.o: shapes.cpp shapes.h simplecanvas.o
	$(CC) $(CFLAGS) -c shapes.cpp

driver: shapes.o simplecanvas.o driver.cpp
	$(CC) $(CFLAGS) -o driver shapes.o simplecanvas.o driver.cpp

clean:
	rm simplecanvas.o shapes.o driver