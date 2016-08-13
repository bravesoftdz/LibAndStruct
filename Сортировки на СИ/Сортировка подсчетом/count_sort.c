#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "count_sort.h"

BOOL SORT_CheckParam(SORT_ValueT Arr[], SORT_CountT ind) {
	SORT_CountT i;

	if (ind < 1 || ind > SORT_COUNT_ARRAY) return FALSE;

	for (i = 0; i < ind; i++) 
		if (Arr[i] < SORT_MIN_VALUE || Arr[i] > SORT_MAX_VALUE) return FALSE;

	return TRUE;
}

void SORT_CountSort(SORT_ValueT Arr[], SORT_CountT ind) {
	SORT_CountT i, j, k = 0;
	SORT_ValueT Crr[SORT_COUNT_VALUE] = {0};

	for (i = 0; i < ind; i++) Crr[Arr[i] - SORT_MIN_VALUE]++;

	for (i = 0; i < SORT_COUNT_VALUE; i++)
		for (j = 0; j < Crr[i]; j++) 
			Arr[k++] = i + SORT_MIN_VALUE;
}