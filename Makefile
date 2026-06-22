CC=cc
CFLAGS=-O2
FILES=main.c fifo.c
PROGNAME=fifotest

all:
	$(CC) $(CFLAGS) $(FILES) -o $(PROGNAME)
