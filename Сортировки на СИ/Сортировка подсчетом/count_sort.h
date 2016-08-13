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

#define SORT_MIN_VALUE -10000 /* Минимальное значение переменной */
#define SORT_MAX_VALUE 10000 /* Максимальное значение переменной */
#define SORT_COUNT_VALUE 20001 /* ABS(MIN) + ABS(MAX) + 1 */

#define SORT_COUNT_ARRAY 1000 /* Колличество хранимых чисел */

typedef int SORT_ValueT; /* Тип хранимых в массиве чисел */
typedef int SORT_CountT; /* Тип количества чисел */

/* Проверка входных параметров */
extern BOOL SORT_CheckParam(SORT_ValueT Arr[], SORT_CountT ind);

/* Сортировка подсчётом */
extern void SORT_CountSort(SORT_ValueT Arr[], SORT_CountT ind);

#endif

