# 生成静态库
* gcc -c hello_fn.c -o hello_fn.o
* ar rcs libhello.a hello_fn.o

# 生成动态库
* -fPIC：生成位置无关码
* gcc -c -fPIC hello_fn.c -o hello_fn.o
* gcc -shared -fPIC hello_fn.o -o libhello.so

* gcc main.c -Wall -L. -lhello -o main

# 运行共享库
* 1.拷贝so
/usr/lib
* 2.更改LD_LIBRARY_PATH
* 3.ldconfig
配置ld.so.conf,然后用ldconfig更新