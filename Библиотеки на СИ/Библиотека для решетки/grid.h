#ifndef GRID_H
#define GRID_H

#include <stdlib.h>

/* ���������� ��� */
#define BOOL int

/* ���������� ������ ��������� */
#define GRID_ParamDataT void*

/* ���������� �������, ���������� ������ ��������� */
typedef void (*GRID_ParamChangeFuncT)(GRID_ParamDataT data);

/* ���������� �������, ������������ �������� � ���������� �������� */
typedef BOOL (*GRID_ParamBOOLFuncT)(GRID_ParamDataT data);

typedef struct {
	GRID_ParamDataT data; /*������ ���������*/
	GRID_ParamChangeFuncT f_next; /*��������� �������� ���������*/
	GRID_ParamChangeFuncT f_init; /*������������� ��������� ��������� ���������*/
	GRID_ParamBOOLFuncT f_is_after_last; /*�������� ����� ����������*/
} GRID_ParamT;


/* ���������� ��������� */
#define GRID_ParamHandleT GRID_ParamT*

/* �������������������� �������� ��������� */
#define GRID_ParamHandleInvalid NULL

/* �������, ��������� ��������. ���������� ����������. */
extern GRID_ParamHandleT GRID_ParamCreate(
	GRID_ParamDataT data,
	GRID_ParamChangeFuncT f_next,
	GRID_ParamChangeFuncT f_init,
	GRID_ParamBOOLFuncT f_is_after_last
);

/* �������, ������������ �������� � �������� ������������. ����������� ������������� ��� ������. */
extern void GRID_ParamDestroy(GRID_ParamHandleT param_handle);


typedef struct {
	GRID_ParamHandleT *param_list; /*������ ����������*/
	int size; /*���������� ���������� (����������� �������)*/
	BOOL is_after_last; /*�������� ����� ����������*/
} GRID_BasicT;

/* ���������� ������� */
#define GRID_HandleT GRID_BasicT*

/* �������������������� �������� ����������� ������� */
#define GRID_HandleInvalid NULL

/* �������, ��������� ������� � �������� ����������� ������������. ���������� ����������. */
extern GRID_HandleT GRID_Create(int param_number);

/* �������, ������������ ������� � �������� ������������. ����������� ������������� �� ������. */
extern void GRID_Destroy(GRID_HandleT grid_handle);

/* �������, ���������������� ��������� �������� ������� �������� ���������. */
extern void GRID_SetParam(
	GRID_HandleT grid_handle,
	int param_idx,
	GRID_ParamHandleT param_handle
);

/* �������, ������������, �������� �� ��������� ��������� ������� ��������� �� ��������. */
extern BOOL GRID_IsAfterLast(GRID_HandleT grid_handle);

/* �������, ����������� ��������� ������� �� ���������. */
extern void GRID_Next(GRID_HandleT grid_handle);

/* �������, ������������ ���������� �� �������� �������� �������. */
extern GRID_ParamDataT GRID_GetParam(GRID_HandleT grid_handle, int param_idx);


#endif
