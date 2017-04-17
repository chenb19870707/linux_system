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
        printf("recv sigal => %d\n",sig);
}

int main()
{
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    if(sigaction(SIGINT,&action,NULL)  < 0)
        ERROR_EXIT("sigaction");



    for(;;)
    {
       pause();
    }
    
    return 0;
}