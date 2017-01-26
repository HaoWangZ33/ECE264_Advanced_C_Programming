##
## Makefile 
##

## Define compiler

CC	= gcc

## Define flags

CFLAGS	= -Wall -Wshadow -Werror -g

## Build rule to build executable, by default, pe04 is build since it 
## is the label of the first rule

pe04: pe04.o answer04.o 
	$(CC) $(CFLAGS) pe04.o answer04.o utility.o -o pe04

## rule to clean up object files and executable so that you can rebuild

clean:	
	rm -f pe04.o answer04.o pe04

## rule to compile .c to .o

%.o:	%.c
	$(CC) $(CFLAGS) -c $<
