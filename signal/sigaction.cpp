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

void  handler(int sig, siginfo_t * siginfo, void *)
{
        printf("recv sigal => %d data = %d\n",sig,siginfo->si_int);
        sleep(5);
}

int main()
{
    struct sigaction action;
    action.sa_sigaction = handler;
    sigaddset(&action.sa_mask,SIGQUIT);
    action.sa_flags = SA_SIGINFO;

    if(sigaction(SIGINT,&action,NULL)  < 0)
        ERROR_EXIT("sigaction");



    for(;;)
    {
       pause();
    }
    
    return 0;
}