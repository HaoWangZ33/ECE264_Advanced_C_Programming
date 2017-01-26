TARGET = pa02
GCC = gcc
CFLAGS = -g -Wall -Wshadow -Werror
CC = $(GCC) $(CFLAGS)
SRCS = pa02.c utility.c answer02.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test:
	$(VALGRIND)=./logfile ./pa02 

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
