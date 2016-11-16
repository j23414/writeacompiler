PROGRAM=basic
CC=g++
DEBUG=-O3
LFLAGS=-Wall
CFLAGS=-c

OBJECTS=lexer.o parser.o emitter.o symbol.o init.o error.o main.o

all:	$(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) -o $(PROGRAM) $(OBJECTS) $(LDFLAGS)

.cpp.o :
	$(CC) $(CFLAGS) -o $@ $<

clean:
	\rm *.o $(PROGRAM)
