flags=-O2 -Wall -std=c23 -I.
ldflags=

.PHONY: clean

all: clean osapi.o

osapi.o: osapi.c osapi.h
	cc $(flags) -c $<

clean:
	rm -f *.o