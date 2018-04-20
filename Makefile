#Compilers
CC = gcc
CFLAGS = -Wall -g -O0

#linker 
LIBS = -lm

OUT = -o
OUTNAME = keyword

all: clean keyword

keyword: 
	$(CC) $(CFLAGS) $(LIBS) main.c util_keyword.c $(OUT) $(OUTNAME)

clean:
		rm -rf *.o keyword 
