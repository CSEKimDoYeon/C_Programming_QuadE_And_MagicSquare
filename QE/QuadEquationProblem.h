#include "Common.h"


void QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation); // ��ü���� ������ �����ϴ� �Լ�.



Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this);
//�������ִ�2����������2 ������0 �������Ǵ��Ѵ�

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this);
//�������ִ�2�����������Ǻ����ǰ��������������Ǵ��Ѵ�.




QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this);


float QuadEquationProblem_determinant(QuadEquationProblem* _this);
//�������ִ�2�����������Ǻ����ǰ�����´�.

Solution QuadEquationProblem_solve(QuadEquationProblem* _this);
//�������ִ�2����������Ǯ���Ͽ�,�ظ���´�.