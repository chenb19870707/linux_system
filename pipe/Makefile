.PHONY=clean all
CC=g++
CFLAGS=-Wall -g
BIN=pipe cmdpipe pipeatomic fifowrite fiforead
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf *.o $(BIN)
