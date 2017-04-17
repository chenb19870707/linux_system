#include <stdio.h>
#include <stdlib.h>

void segfault()
{
	int *p = NULL;
	*p = 100;
}

int main(void)
{
	segfault();
/*
	char buf[1] = "a";
	buf[10003] = 'A';
	printf("%c\n",buf[10003]);
*/
	return 0;
}
