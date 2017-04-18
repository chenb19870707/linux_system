#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define ERROR_EXIT(m) \
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc,char* argv[])
{
    int pipefd[2];
    if(pipe(pipefd) == -1)
        ERROR_EXIT("pipe error");

    pid_t pid;
    pid = fork();
    if(pid == -1)
        ERROR_EXIT("fork error");

    if(pid == 0)
    {
        close(pipefd[0]);

        write(pipefd[1],"hello",5);
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(pipefd[1]);
        char buff[10] = {0};

        read(pipefd[0],buff,sizeof(buff));

        printf(buff);

        printf("\n");

        close(pipefd[0]);
    }

    return 0;
}