# 什么是管道
管道是Unix最古老的进程间通信的形式   
我们把一个进程链接到另一个进程的一个数据流称为管道   
管道的本质是有固定大小的**内核缓冲区**  

# 管道限制
管道是半双工的，数据只能向一个方向流动，需要双方通信时，需要建立起两个管道   
只能用于具有 **共同祖先的进程（具有亲缘关系的进程）** 间通信；通常，一个管道由一个进程创建，然后该进程调用fork，此后父子进程间就可以用该管道通信   

# pipe

pipefd[0] refers to the read end of the pipe.   
pipefd[1] refers to the write end of the pipe  

```cpp
#include <unistd.h>

int pipe(int pipefd[2]);

```
 [父子进程管道读写示例](pipe.cpp)

 [ls | wc -w 模拟](cmdpipe.cpp)

# 管道读写规则
当没有数据可读时   
O_NONBLOCK disable:read调用阻塞，一直等待到有数据到来为止   
O_NONBLOCK enable:read 返回-1，errorno 等于EAGAIN

如果管道写端描述符被关闭，则read返回0   
如果管道读端描述符被关闭，则write操作产生信号SIGPIPE   

In  Linux versions before 2.6.11, the capacity of a pipe was the same as the system page size (e.g., 4096 bytes on i386).  Since Linux 2.6.11, the pipe capacity
       is 65536 bytes

__如果写入的数据量不大于PIPE_BUF时，linux将保证写入原子性__  
__如果写入的数据量大于PIPE_BUF时，linux将不保证写入原子性__

```
O_NONBLOCK disabled, n <= PIPE_BUF
              All n bytes are written atomically; write(2) may block if
              there is not room for n bytes to be written immediately
       阻塞模式时且n<PIPE_BUF:写入具有原子性，如果没有足够的空间供n个字节全部写入，则阻塞直到有足够空间将n个字节全部写入管道       
       O_NONBLOCK enabled, n <= PIPE_BUF
              If there is room to write n bytes to the pipe, then write(2)
              succeeds immediately, writing all n bytes; otherwise write(2)
              fails, with errno set to EAGAIN.
      非阻塞模式时且n<PIPE_BUF：写入具有原子性，立即全部成功写入，否则一个都不写入，返回错误
       O_NONBLOCK disabled, n > PIPE_BUF
              The write is nonatomic: the data given to write(2) may be
              interleaved with write(2)s by other process; the write(2)
              blocks until n bytes have been written.
      阻塞模式时且n>PIPE_BUF：不具有原子性，可能中间有其他进程穿插写入，直到将n字节全部写入才返回，否则阻塞等待写入
       O_NONBLOCK enabled, n > PIPE_BUF
              If the pipe is full, then write(2) fails, with errno set to
              EAGAIN.  Otherwise, from 1 to n bytes may be written (i.e., a
              "partial write" may occur; the caller should check the return
              value from write(2) to see how many bytes were actually
              written), and these bytes may be interleaved with writes by
              other processes.
   非阻塞模式时且N>PIPE_BUF：如果管道满的，则立即失败，一个都不写入，返回错误，如果不满，则返回写入的字节数为1~n，即部分写入，写入时可能有其他进程穿插写入

```

 [大于PIPE_BUF 写入失去原子性示例](pipeatomic.cpp)


 # 命名管道mkfifo
匿名管道由pipe函数创建并打开。   
命名管道由mkfifo函数创建，打开用open。   
FIFO（命名管道）与pipe（匿名管道）之间唯一的区别在它们创建与打开的方式不同，这些工作完成之后，它们具有相同的语义。   
The  only difference between pipes and FIFOs is the manner in which they are created and opened.  Once these tasks have been accomplished, I/O on pipes and FIFOs has exactly the same semantics.

# 命名管道的打开规则
如果当前打开操作是为读而打开FIFO时   
O_NONBLOCK disable：阻塞直到有相应进程为写而打开该FIFO   
O_NONBLOCK enable：立刻返回成功   
如果当前打开操作是为写而打开FIFO时   
O_NONBLOCK disable：阻塞直到有相应进程为读而打开该FIFO   
O_NONBLOCK enable：立刻返回失败，错误码为ENXIO   

 [命名管道写示例](pipewrite.cpp)   
 [命名管道读示例](piperead.cpp)