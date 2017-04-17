.PHONY=clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01fileno 02open 03lseek 04hole 05ls
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf *.o $(BIN)
