#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>


#include <string.h>

#define ERROR_EXIT(m) \
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc,char* argv[])
{
   DIR* dir = opendir(".");
   struct dirent *de;
   while((de = readdir(dir)) != NULL)
   {
       if(strncmp(de->d_name,".",1) == 0)
            continue;

       printf("%s\n",de->d_name);
   }
    return 0;
}
