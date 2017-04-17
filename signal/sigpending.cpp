#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <string>
using namespace std;

#define ERROR_EXIT(m) \
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void handler(int sig)
{
    if(sig == SIGINT)
        printf("recv sigal => %d\n",sig);
    else if(sig == SIGQUIT)
    {
        sigset_t unset;
        sigemptyset(&unset);
        sigaddset(&unset,SIGINT);
        sigprocmask(SIG_UNBLOCK,&unset,NULL);
    }
}

void printsigset(sigset_t *set)
{
    for(int i =1;i < NSIG;i++)
    {
        if(sigismember(set,i))
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }
    }

    printf("\n");
}

int main()
{
    sigset_t pset;
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigprocmask(SIG_BLOCK,&set,NULL);

    if(signal(SIGINT,handler) == SIG_ERR)
        ERROR_EXIT("signal");
    
    if(signal(SIGQUIT,handler) == SIG_ERR)
        ERROR_EXIT("signal");


    for(;;)
    {
       sigpending(&pset);
       printsigset(&pset);
       sleep(1);
    }
    
    return 0;
}