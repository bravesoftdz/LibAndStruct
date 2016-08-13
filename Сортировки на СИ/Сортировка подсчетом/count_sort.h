#ifndef COUNT_SORT_H
#define COUNT_SORT_H

#include <stdlib.h>

#ifdef DEFINE_BOOL 
#define BOOL int
#define FALSE 0
#define TRUE 1
#else
typedef enum {
	FALSE,
	TRUE
} BOOL;
#endif

#define SORT_MIN_VALUE -10000 /* ����������� �������� ���������� */
#define SORT_MAX_VALUE 10000 /* ������������ �������� ���������� */
#define SORT_COUNT_VALUE 20001 /* ABS(MIN) + ABS(MAX) + 1 */

#define SORT_COUNT_ARRAY 1000 /* ����������� �������� ����� */

typedef int SORT_ValueT; /* ��� �������� � ������� ����� */
typedef int SORT_CountT; /* ��� ���������� ����� */

/* �������� ������� ���������� */
extern BOOL SORT_CheckParam(SORT_ValueT Arr[], SORT_CountT ind);

/* ���������� ��������� */
extern void SORT_CountSort(SORT_ValueT Arr[], SORT_CountT ind);

#endif

