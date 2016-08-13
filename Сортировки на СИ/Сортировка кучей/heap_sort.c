#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap_sort.h"

static void SORT_Heap(SORT_ValueT A[], int N, int parent) {
	SORT_CountT left = 2 * parent + 1; 
	SORT_CountT right = 2 * parent + 2;  
	SORT_ValueT tmp;
	if(left < N)
		if (A[parent] <= A[left]) {
			tmp = A[left];
			A[left] = A[parent];
			A[parent] = tmp;
			SORT_Heap(A, N, left);
		}
	if(right < N)
		if (A[parent] <= A[right]) {
			tmp = A[right];
			A[right] = A[parent];
			A[parent] = tmp;
			SORT_Heap(A, N, right);
		}
}

BOOL SORT_CheckParam(SORT_ValueT Arr[], SORT_CountT ind) {
	SORT_CountT i;

	if (ind < 1 || ind > SORT_COUNT_ARRAY) return FALSE;

	for (i = 0; i < ind; i++) 
		if (Arr[i] < SORT_MIN_VALUE || Arr[i] > SORT_MAX_VALUE) return FALSE;

	return TRUE;
}

void SORT_HeapSort(SORT_ValueT Arr[], SORT_CountT ind) {
	SORT_CountT i, H = ind;
	SORT_ValueT tmp;

	for(i = ind - 1; i >= 0; i--) SORT_Heap(Arr, ind, i);

	for(i = 0; i < ind; i++){
		tmp = Arr[0];
		Arr[0] = Arr[H - 1];
		Arr[H - 1] = tmp;
		H--; 
		SORT_Heap(Arr, H, 0);
	}
}