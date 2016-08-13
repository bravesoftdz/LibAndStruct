#ifndef VECT_H
#define VECT_H

typedef void * VECT_Handle; /* ���������� ������� */
typedef double VECT_Vtype; /* ��� ��������� � ������� �������� */
typedef int BOOL; /* ���������� ��� ������ */

/* ������� ����� ������, ���������� ��������� �� ���������� ������ */
extern VECT_Handle VECT_Create(int n);
/* ������� ������ ������ � ������� ��� �� ������� */
extern void VECT_Destroy(VECT_Handle v1);
/* �������������� �������� ������� */ 
extern VECT_Handle VECT_CreateAlternative(int n, VECT_Vtype * values);
/* �������������� �������� ������� */ 
extern VECT_Handle VECT_Create_and_Fill(int n, ...);

/* ���������� �������� �� ����� �� ��������� ������� */
extern VECT_Vtype VECT_GetValue(VECT_Handle v1, int n);
/* ���������� ��������� �� �������� �� ����� �� ��������� ������� */
extern VECT_Vtype * VECT_GetValuePointer(VECT_Handle v1, int n);
/* �������� �������� ������� */
extern void VECT_SetValue(VECT_Handle v1, int n, VECT_Vtype value);

/* ����� ����������� ��������� � ������� */
extern int VECT_Length(VECT_Handle v1);

/* ����� ������� (������) */
extern VECT_Vtype VECT_Len(VECT_Handle v1);

/* ��������� �������� (�������� / ��������� / ��������� / �������) �� ���� ��������� ������� */
/* sign - ���� �������� (+ / - / * / /)                                                      */
extern VECT_Handle VECT_ChangeByValue(VECT_Handle v1, VECT_Vtype value, char sign);
/* ��������� �������� (�������� / ��������� / ��������� / �������) �� ���� ��������� ������� */
/* sign - ���� �������� (+ / - / * / /)                                                      */
extern VECT_Handle VECT_ChangeByVector(VECT_Handle v1, VECT_Handle v2, char sign);

/* �������������� �������� */
extern BOOL VECT_Collinearity(VECT_Handle v1, VECT_Handle v2);
/* ��������� ������������ �������� */
extern VECT_Vtype VECT_Dot(VECT_Handle v1, VECT_Handle v2);
/* ��������� ������������ �������� */
extern VECT_Handle VECT_Cross_3(VECT_Handle v1, VECT_Handle v2);

/* ���������� ��������� �� ������ �� ���������� ������� */
extern VECT_Vtype * VECT_GetMap(VECT_Handle v1);
/* ��������� ��������� �������� ������� */
extern BOOL VECT_CompareMap(VECT_Vtype * m1, VECT_Vtype * m2, int size);

/* C�������� ���� �������� �� n-�� */
extern BOOL VECT_CompareVector(VECT_Handle v1, VECT_Handle v2, float n);

#endif