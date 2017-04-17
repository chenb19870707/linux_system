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

struct TEST
{
    int a;
    string b;
};

TEST g_data;

void unsafefunc()
{
    printf("a=%d,b=%s\n",g_data.a,g_data.b.c_str());
}

void handler(int sig)
{
    unsafefunc();
    alarm(1);
}

int main()
{
    TEST zeros = {0,"你好124"};
    TEST ones = {1,"你不好567"};

    if(signal(SIGALRM,handler) == SIG_ERR)
        ERROR_EXIT("signal");

    g_data = zeros;   
    alarm(1);

    for(;;)
    {
        g_data = zeros;
        g_data = ones;
    }
    
    return 0;
}