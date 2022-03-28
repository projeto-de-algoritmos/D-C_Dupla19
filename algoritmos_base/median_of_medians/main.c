#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "mergeSort.h"
/*
    Author: Maicon Mares
    Date: 19/03/2022
    Software Engineering undergraduate student
*/

// This implementation doesn't allow repeated numbers :(

Item median(Item *v, int i, int l, int r)
{
	int k = 0, begin = l, end = l + 4, medianIdx = -1;
	int l1 = l, r1 = r;

	Item *M = (Item *)malloc(sizeof(Item) * (r - l + 1));
	Item MOM;

	while ((r1 - l1 + 1) >= 5)
	{
		mergeSort(v, begin, end);
		medianIdx = (begin + end) / 2;
		M[k++] = v[medianIdx];

		begin = end + 1;
		end = begin + 4;
		l1 += 5;
	}

	if ((r1 - l1 + 1) > 0)
	{
		mergeSort(v, l1, r1);
		medianIdx = (l1 + r1) / 2;
		M[k++] = v[medianIdx];
	}

	if (k <= 5)
		MOM = M[k / 2];
	else
		MOM = median(M, k/2, 0, k-1);

	Item *low = (Item *) malloc(sizeof(Item)*(r-l+1));
	Item *high = (Item *) malloc(sizeof(Item)*(r-l+1));

	int p = 0, q = 0;

	for (int z = l; z <= r; z++)
	{
		if (v[z] < MOM)
			low[p++] = v[z];
		else if (v[z] > MOM)
			high[q++] = v[z];
	}

	if (p == i-1)
		return MOM;
	else if (p > i-1)
		return median(low, i, 0, p-1);
	else
		return median(high, i-p-1, 0, q-1);

	free(M);
	free(low);
	free(high);
}

int main(void)
{
	Item A[10] = {25, 21, 98, 100, 76, 22, 43, 60, 89, 87};

	printf("Insert the index of k-ith smallest number you want to find in the list above\n");
	printf("{25, 21, 98, 100, 76, 22, 43, 60, 89, 87}\n");

	int idx = -1;
	scanf("%d", &idx);

	Item kth = median(A, idx, 0, 9);

	printf("The %dith smallest number is: %d\n", idx, kth);

	return 0;
}