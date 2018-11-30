#ifndef AppIO_h
#define AppIO_h

#include "Common.h"
#include <stdio.h>

//출력함수
void AppIO_out_msg_startSolvingQuadEquation(void);
void AppIO_out_msg_endSolvingQuadEquation(void);

void AppIO_out_msg_secondOrderTermCoefficientIsZero(void);
void AppIO_out_msg_determinantIsNegative(float aDeterminant);
void AppIO_out_quadEquation(float c0, float c1, float c2);
void AppIO_out_solution(float root1, float root2);

//입력함수
Boolean AppIO_in_solvingIsRequested();
void AppIO_in_quadEquation(float* p_c0, float* p_c1, float* p_c2);
#endif
