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
    if(argc !=3)
    {
        fprintf(stdout,"Usage %s src dest\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int infd = open(argv[1],O_RDONLY);
    if(infd == -1)
    {
        ERROR_EXIT("open src error");
    }

    int outfd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0777);
    if(outfd == -1)
    {
        ERROR_EXIT("open desc error");
    }

    char buf[1024];
    int nread = 0;
    while((nread = read(infd,buf,1024)) > 0)
    {
        write(outfd,buf,nread);
    }

    close(infd);
    close(outfd);
    return 0;
}
