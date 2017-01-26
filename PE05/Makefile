TARGET = pe05
GCC = gcc
CFLAGS = -g -Wall -Wshadow -Werror
CC = $(GCC) $(CFLAGS)
SRCS = pe05.c utility.c answer05.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test:
	$(VALGRIND)=./logfile ./pe05 

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
