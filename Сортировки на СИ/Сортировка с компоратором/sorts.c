#include "sorts.h"

void Swap(void *a, void *b, int tsize) {
	void *c = malloc(tsize);
	memcpy(c, a, tsize);
	memcpy(a, b, tsize);
	memcpy(b, c, tsize);
	free(c);
};

void BubbleSort(void *a, int n, int (*fn)(void *, void *), int tsize) {
	int i, j;
	int LeftA, RightA;

	for(i = 0; i <= n; i++)
		for(j = 0; j < n - i; j++) {
			if (fn(LeftA = a + tsize * j, RightA = a + tsize * (j+1)) > 0) {
				Swap(LeftA, RightA, tsize);
			}
		}
};

void QuickSort(void *a, int n, int (*fn)(void *, void *), int tsize) {

	int i = 0, j = n;
	void *p = malloc(tsize);
	memcpy(p, a + tsize * (n >> 1), tsize);

	do {
		while (fn(a + tsize * i, p) < 0) i++;
		while (fn(a + tsize * j, p) > 0) j--;

		if (i <= j) {
			Swap(a + tsize * i, a + tsize * j,  tsize);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) QuickSort(a, j, fn, tsize);
	if (n > i) QuickSort(a + i * tsize, n - i, fn, tsize);
};

void Merge(void *a, int lb, int split, int ub, int (*fn)(void *, void *), int tsize) {

	int pos1 = lb;
	int pos2 = split + 1;
	int pos3 = 0;
	void *temp = calloc(ub - lb + 1, tsize);

	while (pos1 <= split && pos2 <= ub) {

		if (fn(a + pos1 * tsize, a + pos2 * tsize) < 0)
			memcpy(temp + tsize * pos3++, a + tsize * pos1++, tsize);
		else
			memcpy(temp + tsize * pos3++, a + tsize * pos2++, tsize);
}

	while (pos2 <= ub)
		memcpy(temp + tsize * pos3++, a + tsize * pos2++, tsize);
	while (pos1 <= split)  
		memcpy(temp + tsize * pos3++, a + tsize * pos1++, tsize);

	for (pos3 = 0; pos3 < ub - lb + 1; pos3 ++)
		memcpy(a + tsize * (lb + pos3), temp + tsize * pos3, tsize);

	free(tsize);
};

void MergeSortRecursive(void *a, int lb, int ub, int (*fn)(void *, void *), int tsize) {
	int split;

	if (lb < ub) {

		split = (lb + ub) >> 1;

		MergeSortRecursive(a, lb, split, fn, tsize);
		MergeSortRecursive(a, split + 1, ub, fn, tsize);
		Merge(a, lb, split, ub, fn, tsize); 
	}
};

void MergeSort(void *a, int ub, int (*fn)(void *, void *), int tsize) {
	MergeSortRecursive(a, 0, ub, fn, tsize);
};