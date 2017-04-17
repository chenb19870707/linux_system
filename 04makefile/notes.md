# make常用的内嵌函数
+ 函数调用  
$(function arguments)  
+ $(wildcard PATTERN)  
当前目录下匹配模式的文件  
src=$(wildcard *.c)
+ $(patsubst PATTERN,REPLACEMENT,TEXT)  
模式替换函数  
例如:$(patsubst %.c,%.o,$src)  
等价于$(src:.c=.o)
+ shell函数  
执行shell命令  
例如$(shell ls -d */)  

# 多层级Makefile
```Makefile
CC      = gcc
CFLAGS  =-Wall -g
BIN     = main
SUBDIR  = $(shell ls -d */)
ROOTSRC = $(wildcard *.c)
ROOTOBJ = $(ROOTSRC:%.c=%.o)
SUBSRC  = $(shell find $(SUBDIR) -name '*.c')
SUBOBJ  = $(SUBSRC:%.c=%.o)

$(BIN):$(ROOTOBJ) $(SUBOBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(ROOTOBJ) $(SUBOBJ)
%o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN) $(ROOTOBJ) $(SUBOBJ)
```
