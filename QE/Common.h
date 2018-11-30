#ifndef C1_quadEquation_Common_h
#define C1_quadEquation_Common_h

#include <math.h>
#define MAXFLOAT 1.0E+100// only for Windows
#define EPSILON 1.0E-6
#define FloatValueIsZero(NUMBER)(fabsf(NUMBER) < EPSILON)

typedef struct {
	float _root1;
	float _root2;
} Solution;
typedef struct {
	float _c0;
	float _c1;
	float _c2;
} QuadEquation;
typedef struct {
	QuadEquation _equation;
} QuadEquationProblem;

typedef enum { FALSE, TRUE } Boolean;
//Boolean bool;

#endif