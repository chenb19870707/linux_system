#include <stdio.h>
#include <stdlib.h>

long func(int n);

int main(int argc, char *argv[])
{
	int i;
	int x =5;
	double z = 2.5;
	char ch = 'q';

	int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *arr2 = (int *)malloc(sizeof(int) * 10);
	for (i=0; i<10; ++i)
	{
		arr2[i] = i;
	}

	printf("Entering main ...\n");
	for (i=0; i<argc; ++i)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");
	long result = 0;
	for (i=1; i<=100; ++i)
	{
		result += i;
	}
	printf("result[1-100] = %ld\n", result);
	printf("result[1-10] = %ld\n", func(10));

	printf("Exiting main ...\n");
	return 0;
}

long func(int n)
{
	long sum = 0;
	int i;
	for (i=1; i<=n; ++i)
	{
		sum += i;
	}

	return sum;
}
