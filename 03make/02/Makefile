.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01test 02test 03test 04test
all:$(BIN)
#%.o:%.c
#	$(CC) $(CFLAGS) -c $< -o $@
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
01test:01test.o
	$(CC) $(CFLAGS) $^ -o $@
02test:02test.o
	$(CC) $(CFLAGS) $^ -o $@
03test:03test.o pub.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f *.o $(BIN)
