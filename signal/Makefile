.PHONY=clean all
CC=g++
CFLAGS=-Wall -g
BIN=reentryfunc sigpending
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf *.o $(BIN)
