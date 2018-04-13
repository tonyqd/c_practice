#Compilers
CC = gcc
CFLAGS = -Wall -g -O0

#linker 
LIBS = -lm

LIBPOS=libpos.a

#include Files
SRCS = util_keyword.c
OBJS =  $(addsuffix .o, $(basename $(SRCS)))

all: keyword

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
		
keyword: main.c $(LIBPOS)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
		
$(LIBPOS) : $(OBJS)

clean:
		rm -rf *.o keyword $(LIBPOS)
