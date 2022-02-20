CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: driver

simplecanvas.o: simplecanvas/simplecanvas.h simplecanvas/simplecanvas.cpp
	$(CC) $(CFLAGS) -c simplecanvas/simplecanvas.cpp

shape.o: shape.cpp shape.h simplecanvas.o
	$(CC) $(CFLAGS) -c shape.cpp

point.o: point.cpp point.h shape.o
	$(CC) $(CFLAGS) -c point.cpp

linesegment.o: linesegment.cpp linesegment.h shape.o point.o
	$(CC) $(CFLAGS) -c linesegment.cpp

driver: shape.o simplecanvas.o point.o linesegment.o driver.cpp
	$(CC) $(CFLAGS) -o driver shape.o simplecanvas.o point.o linesegment.o driver.cpp

clean:
	rm simplecanvas.o shape.o point.o linesegment.o driver