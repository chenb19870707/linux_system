.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=simple main
all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
main:main.o search.o
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f *.o $(BIN)
