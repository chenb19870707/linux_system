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

        dup2(pipefd[1],STDOUT_FILENO);
        close(pipefd[1]);
        execlp("ls","ls",NULL);
        fprintf(stderr,"error excute ls\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        close(pipefd[1]);

        dup2(pipefd[0],STDIN_FILENO);
         close(pipefd[0]);
        execlp("wc","wc","-w",NULL);
        fprintf(stderr,"error excute ls\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}