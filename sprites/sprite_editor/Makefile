# Makefile for sprite scripts - gfighter

CC=gcc
CFLAGS=-Wall -O6 -g -fPIC -I../../src -I.
LIBNAME=triggers.dll
LDFLAGS=  -shared -Wl,-soname,$(LIBNAME) 
OBJECTS=triggers.o 

all: $(OBJECTS) 
	$(CXX) $(LDFLAGS) -o $(LIBNAME) $(OBJECTS) 	 

clean:
	rm -rf *.o  core
