#==============================================================================
# Makefile Poly
#==============================================================================
CC		:= g++
CFLAGS	:= -Wall -std=c+11 

.PHONE: all clean

all:  poly.out

poly.out:	poly.o
poly.o:		poly.cpp

%.out: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<
clean:
	$(RM) $(wildcard *.[o])
