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
    int infd = open("test.txt",O_RDONLY);
    if(infd == -1)
    {
        ERROR_EXIT("open src error");
    }

    char buf[1024];
    int nread = read(infd,buf,5);

    int ret = lseek(infd,0,SEEK_CUR);
    if(ret == -1)
    {
        ERROR_EXIT("lseek");
    }

    printf("cur offset = %d\n",ret);
   

    close(infd);
    return 0;
}
