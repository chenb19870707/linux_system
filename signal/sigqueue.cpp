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

int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        printf("Usage %s pid\n",argv[0]);
        exit(EXIT_FAILURE);
    }


    int pid = atoi(argv[1]);

    sigval_t value;
    value.sival_int = 100;
    sigqueue(pid,SIGINT,value);
    
    return 0;
}