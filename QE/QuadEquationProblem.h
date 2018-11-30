#include "Common.h"


void QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation); // 객체에게 정보를 제공하는 함수.



Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this);
//가지고있는2차방정식의2 차항이0 인지를판단한다

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this);
//가지고있는2차방정식의판별식의값이음수인지를판단한다.




QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this);


float QuadEquationProblem_determinant(QuadEquationProblem* _this);
//가지고있는2차방정식의판별식의값을얻는다.

Solution QuadEquationProblem_solve(QuadEquationProblem* _this);
//가지고있는2차방정식을풀게하여,해를얻는다.