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
    int infd = open("hole.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(infd == -1)
    {
        ERROR_EXIT("open src error");
    }

    write(infd,"ABCDE",5);

    lseek(infd,1024*1024*1024,SEEK_CUR);

    write(infd,"HJKLM",5);
   

    close(infd);
    return 0;
}
