#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quick_sort.h"

static void SORT_QSort(SORT_ValueT A[], SORT_CountT left, SORT_CountT right) {
	SORT_CountT l = left, r = right, m, k;

	if(left >= right) return;

	m = A[rand() % (right - left + 1) + left];

	do {
		while(A[l] < m)
			l++;
		while(A[r] > m)
			r--;
		if(l <= r) {
			k = A[l];
			A[l] = A[r];
			A[r] = k;
			l++; 
			r--;
		}
	} while (l <= r);

	SORT_QSort(A, left, r); 
	SORT_QSort(A, l, right);
}

BOOL SORT_CheckParam(SORT_ValueT Arr[], SORT_CountT ind) {
	SORT_CountT i;

	if (ind < 1 || ind > SORT_COUNT_ARRAY) return FALSE;

	for (i = 0; i < ind; i++) 
		if (Arr[i] < SORT_MIN_VALUE || Arr[i] > SORT_MAX_VALUE) return FALSE;

	return TRUE;
}

void SORT_QuickSort(SORT_ValueT Arr[], SORT_CountT ind) {
	SORT_QSort(Arr, 0, ind - 1);
}