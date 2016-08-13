#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "count_sort.h"

SORT_ValueT A[SORT_COUNT_ARRAY];
SORT_CountT N = 0;

void LoadFromFile(const char file_name[]) {
	FILE *in = fopen(file_name, "r");
	if (in == NULL) {printf("ERROR READ FILE: %s\n", file_name); return;}
	fscanf(in, "%i", &N);
	N = 0;
	while(!feof(in)) {
		N++;
		fscanf(in, "%i", &A[N - 1]);
	}
	fclose(in);
}

void SaveToFile(const char file_name[]) {
	SORT_CountT i;
	FILE *out = fopen(file_name, "w");
	if (out == NULL) {printf("ERROR WRITE FILE: %s\n", file_name); return;}
	for (i = 0; i < N; i++) fprintf(out, " %i", A[i]);
	fclose(out);
}

void RunTest(const char file[]) {
	char in_file[32] = "TESTS_IN/";
	char out_file[32] = "TESTS_OUT/";

	strcat(in_file, file);
	strcat(in_file, "_IN.txt");
	LoadFromFile(in_file);
	strcat(out_file, file);
	strcat(out_file, "_OUT.txt");

	if (SORT_CheckParam(A, N) == TRUE) {
		SORT_CountSort(A, N);
		SaveToFile(out_file);
	} else {
		N = 1;
		A[0] = 0;
		SaveToFile(out_file);
	}
}

int main() {

	RunTest("TEST_1");
	RunTest("TEST_2");
	RunTest("TEST_3");
	RunTest("TEST_4");
	RunTest("TEST_5");
	RunTest("TEST_6");
	RunTest("TEST_7");
	RunTest("TEST_8");
	RunTest("TEST_9");
	RunTest("TEST_10");
	RunTest("TEST_11");
	RunTest("TEST_12");
	RunTest("TEST_13");
	RunTest("TEST_14");
	RunTest("TEST_15");
	RunTest("TEST_16");
	RunTest("TEST_17");
	RunTest("TEST_18");
	RunTest("TEST_19");
	RunTest("TEST_20");
	RunTest("TEST_21");
	RunTest("TEST_22");
	RunTest("TEST_23");
	RunTest("TEST_24");
	RunTest("TEST_25");
	RunTest("TEST_26");
	RunTest("TEST_27");
	RunTest("TEST_28");
	RunTest("TEST_29");
	RunTest("TEST_30");
	RunTest("TEST_31");
	RunTest("TEST_32");
	RunTest("TEST_33");
	RunTest("TEST_34");
	RunTest("TEST_35");
	RunTest("TEST_36");
	RunTest("TEST_37");
	RunTest("TEST_38");
	RunTest("TEST_39");
	RunTest("TEST_40");

	return 0;
}