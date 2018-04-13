#Compilers
CC = gcc
CFLAGS = -Wall -g -O0

#linker 
LIBS = -lm

OUT = -o

all: keyword

keyword: 
	$(CC) $(LIBS) main.c util_keyword.c $(OUT) keyword

clean:
		rm -rf *.o keyword 
		echo "clean successfully!"
