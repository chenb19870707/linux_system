#include "search.h"

int seq_search(int list[], int start, int n, int key)
{
	int i;
	for (i=start; i<n; ++i)
	{
		if (list[i] == key)
			return i;
	}

	return -1;
}

