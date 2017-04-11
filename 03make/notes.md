# Makefile自动化变量
1. $@ 规则的目标文件名
2. $< 规则的第一个文件名
3. $^ 规则所以的文件名

# Makefile示例
```Makefile
.PHONY:clean
OBJECTS=main.o add.o sub.o
main:$(OBJECTS)
	gcc -Wall -g $^ -o $@
main.o:main.c
	gcc -Wall -g -c $< -o $@
add.o:add.c add.h
	gcc -Wall -g -c $< -o $@
sub.o:sub.c sub.h
	gcc -Wall -g -c $< -o $@
clean:
	rm -f main $(OBJECTS)
 ```

# 多目标Makefile
```Makefile
 .PHONY:clean all
CC=gcc
CFLAGS=-Wall -g
BIN=01test 02test 03test 04test
all:$(BIN)
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
 ```