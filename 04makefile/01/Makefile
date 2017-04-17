CC		= gcc
FLAGS	= -Wall -g
BIN		= main
SUBDIR	= $(shell ls -d */)
ROOTSRC	= $(wildcard *.c)
ROOTOBJ	= $(ROOTSRC:%.c=%.o)
SUBSRC	= $(shell find $(SUBDIR) -name '*.c')
SUBOBJ	= $(SUBSRC:%.c=%.o)

$BIN:$(ROOTOBJ) $(SUBOBJ)
	$(CC) $(FLAGS)  -o $(BIN) $(ROOTOBJ) $(SUBOBJ)
%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(ROOTOBJ) $(SUBOBJ) $(BIN)