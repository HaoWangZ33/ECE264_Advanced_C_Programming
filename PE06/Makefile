TARGET = pe06
GCC = gcc
DEFINES = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
CFLAGS = -g -Wall -Wshadow -Werror $(DEFINES)
CC = $(GCC) $(CFLAGS) $(DEFINES)
SRCS = pe06.c utility.c answer06.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

test:
	$(VALGRIND)=./logfile ./pe06 

.c.o:
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f $(OBJS) $(TARGET)
