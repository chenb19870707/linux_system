.PHONY=clean all
CC=g++
CFLAGS=-Wall -g
BIN=zomble
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf *.o $(BIN)
