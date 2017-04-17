#include <stdio.h>
#include "search.h"

int main(int argc, char *argv[])
{
	printf("Entering main ...\n");
	int i;
	for (i=0; i<argc; i++)
	{
		printf("%s ",argv[i]);
	}
	printf("\n");
	int a[10] = {1, 3, 8, 9, 8, 3, 8, 6, 9, 2};
	int key = 8;
	int pos;
	int count = 0;
	
	pos = 0;
	while ((pos=seq_search(a, pos, 10, key)) != -1)
	{
		count++;
		pos++;
	}

	printf("%d occurs %d times in the list\n", key, count);
	printf("Exiting main ...\n");
	return 0;
}
