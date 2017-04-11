.PHONY=clean
OBJECTS=main.o add.o sub.o
main:$(OBJECTS)
	gcc -Wall -g $^ -o $@
main.o:main.c
	gcc -Wall -g -c $< -o $@
add.o:add.c
	gcc -Wall -g -c $< -o $@
sub.o:sub.c
	gcc -Wall -g -c $< -o $@
clean:
	rm -rf main $(OBJECTS)