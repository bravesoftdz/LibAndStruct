#ifndef MATR_H
#define MATR_H

typedef void * MATR_Handle; /* ���������� ������� */
typedef double MATR_Mtype; /* ��� �������� � ������� �������� */
typedef int BOOL; /* ���������� ��� ������ */

/* �������� ������ ��� �������, ���������� ��������� �� �� */
extern MATR_Handle MATR_Create(int n);
/* �������� ��������� ������� */
extern MATR_Handle MATR_CreateIdentity(int n);
/* �������������� �������� ����� ������� */
extern MATR_Handle MATR_CreateAlternative(int n, MATR_Mtype * values);
/* �������������� �������� ����� ������� */
extern MATR_Handle MATR_Create_and_Fill(int n, ...);

/* �������� ������� � �������� ������ */
extern void MATR_Destroy(MATR_Handle v1);

/* ���������� ������ ������� */
extern int MATR_Size(MATR_Handle v1);
/* ����� ���������� ����� � ������� */
extern int MATR_Length(MATR_Handle v1);
/* ���������� ��������� �� ������ �� ���������� ������� */
extern MATR_Mtype * MATR_GetMap(MATR_Handle v1);

/* ��������� ��������� �������� ���� ������ */
extern BOOL MATR_CompareMap(MATR_Mtype * m1, MATR_Mtype * m2, int size);
/* ��������� ���� ������ �� n-�� */
extern BOOL MATR_CompareMatrix(MATR_Handle v1, MATR_Handle v2, float n);

/* ���������� �������� �������� ������� */
extern MATR_Mtype MATR_GetValue(MATR_Handle v1, int y, int x);
/* ���������� ��������� �� ������� ������� */
extern MATR_Mtype * MATR_GetValuePointer(MATR_Handle v1, int y, int x);
/* �������� �������� �������� */
extern void MATR_SetValue(MATR_Handle v1, int y, int x, MATR_Mtype value);

/* ������� ������� ������� ����� (���������� � ������������ ����) */
extern MATR_Handle MATR_Gauss(MATR_Handle v1);
/* ���������� ������������ ������� */
extern MATR_Mtype MATR_Determinant(MATR_Handle v1);
/* ���������������� ������� */
extern MATR_Handle MATR_Transposed(MATR_Handle v1);
/* ���������� �������� ������� */
extern MATR_Handle MATR_Inverse(MATR_Handle v1);  

/* ������������ ������ */
extern MATR_Handle MATR_Multiplication(MATR_Handle v1, MATR_Handle v2);
/* �������� �� ���������� ������� (��������/���������/���������/������� �� �����) */
/* sign ��������� ���� ��������� ���������� ��������� �������� (+, -, *, /)       */
extern MATR_Handle MATR_ChangeByValue(MATR_Handle v1, MATR_Mtype value, char sign);
/* �������� �� ���������� ������� (��������/���������/���������/������� �� �����) */
/* sign ��������� ���� ��������� ���������� ��������� �������� (+, -, *, /)       */
extern MATR_Handle MATR_ChangeByMatrix(MATR_Handle v1, MATR_Handle v2, char sign);

#endif