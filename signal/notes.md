# kill发送信号  
kill(pid,sig)  
pid>0:信号sig发送进程号=pid的进程
pid=0:信号sig将被发送给调用者所在组的每一个进程   
pid=-1:信号sig将被发送给所有有权限发送的进程，除1号进程和自身之外  
pid<0:信号sig将发送给进程组 =-pid中的每一个进程

# raise给自己发送信号  
等价于kill(getpid(),sig)

# killpg向进程组发送信号
等价于kill(getpgrp(),sig)

# pause
将进程置为终端睡眠状态。然后调用schedule(),使linux进程调度器找到另一个进程来运行。  
pause 让出CPU，指导信号被捕获。

# alarm 发送 SIGALRM


# settimer 发送SIGALRM SIGVTALRM SIGPROF

# abort 发送 SIGABRT

# 可重入函数
所谓可冲入函数是指一个可以被多个任务调用的过程，任务在调用时不必担心数据是否会出错。因为进程在收到信号后，就将跳转到信号处理函数去执行。如果信号处理函数中使用了不可重入函数，那么信号处理函数可能会**修改原来进程中不应该修改的数据，这样进程从信号处理函数中返回接着执行时，可能会出现不可预料的后果**。不克重入函数在信号处理函数中视为不安全函数。  

满足下列条件的函数是不可重入的   
1. 使用静态的数据结构，如getlogin(),gettime(),getgrgid(),getgrnam(),getpwuid()以及getpwnam等等。
2. 函数实现时，调用了malloc()或者free()函数。
3. 实现时使用了标准IO函数

**不可重入函数不能再信号处理函数中调用，不然可能会产生不可预料的问题**

 [代码示例](reentryfunc.cpp) , 出现了a=0,b=你不好567

```
a=0,b=你好124
a=1,b=你好124
a=0,b=你不好567
```


# 信号集操作

信号屏蔽字结构sigset_t 操作，改变这个变量，不会改变进程中的信号屏蔽字   
``` CPP
#include <signal.h>

int sigemptyset(sigset_t *set);  // 清空64位信号集
int sigfillset(sigset_t *set);   // 全置1
int sigaddset(sigset_t *set, int signum); //对应位置1
int sigdelset(sigset_t *set, int signum); //对应位置0
int sigismember(const sigset_t *set, int signum); //检测对应位是0还是1
```

改变或者获取进程中的信号屏蔽字

``` CPP
#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```
oldset若非空指针，表示改变前的

| how           | 说明           |
| ------------- |:-------------:|
| SIG_BLOCK     | 添加屏蔽字，相当于mask = mask | set |
| SIG_UNBLOCK   | 删除屏蔽字，相当于 mask = mask & set    |  
| SUG_SETMASK   | 设置，相当于mask = set      |  


 [代码示例](sigpending.cpp)

 # sigaction 注册信号
```CPP
    int sigaction(int signum, const struct sigaction *act,
                    struct sigaction *oldact);

    struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
    };
                
```

***sa_handler 和 sa_sigaction 只能使用其一***  
sa_handler用于不可靠信号  
sa_sigaction 可用于可靠信号的注册，不能带参数

sa_mask 定在信号处理程序执行过程中，哪些信号应当被阻塞,信号处理函数结束后才会递达。缺省情况下当前信号本身被阻塞，防止信号的嵌套发送
sa_flags 标志

**传递参数时sa_flags必须设置成SA_SIGINFO**
```
    struct sigaction action;
    action.sa_sigaction = handler;
    sigaddset(&action.sa_mask,SIGQUIT);
    action.sa_flags = SA_SIGINFO;

    if(sigaction(SIGINT,&action,NULL)  < 0)
        ERROR_EXIT("sigaction");

```

 [代码示例](sigaction.cpp)
