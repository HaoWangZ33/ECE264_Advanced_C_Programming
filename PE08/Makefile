TARGET = pe08
GCC = gcc
DEFINES = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
CFLAGS = -g -Wall -Wshadow -Werror $(DEFINES)
CC = $(GCC) $(CFLAGS) $(DEFINES)
SRCS = pe08.c answer08.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test:
	$(VALGRIND)=./logfile ./pe08 

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
