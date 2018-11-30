#include "QuadEquationProblem.h"

void QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation) { // ��ü���� ������ �����ϴ� �Լ�.
	_this->_equation = anEquation;
}

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this) { 
	//�������ִ�2����������2 ������0 �������Ǵ��Ͽ������ش�
	 
	return FloatValueIsZero(_this->_equation._c2);
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this) { 
	//�������ִ�2�����������Ǻ����ǰ��������������Ǵ��Ͽ������ش�
	float determinant = QuadEquationProblem_determinant(_this) ; 
	if (determinant < 0)
		return TRUE;
	else
		return FALSE;
	 
}

/* ��ü�� �����̳� ������ ����� ���� �Լ� */

QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this) {

}

float QuadEquationProblem_determinant(QuadEquationProblem* _this) {
	//�������ִ�2�����������Ǻ����ǰ�������Ͽ������ش�, D = b^2-4ac
	QuadEquationProblem qeProblem = *_this; 
	
	float determinant = ((qeProblem._equation._c1)*(qeProblem._equation._c1)) 
		- (4 * (qeProblem._equation._c2)*(qeProblem._equation._c0));

	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem* _this) { 
	Solution solution;
	float determinant = QuadEquationProblem_determinant(_this);
	// ��ü����������Ű����(�̸��׸�main()) ��������ϴ��Լ�������,
	// �̷��԰�ü�ڽŵ��ʿ��ϸ����Ѵ�.
	float sqrtDeterminant = sqrt(determinant); // <math.h>���ݵ��include
	solution._root1 = (-(_this->_equation._c1) + sqrtDeterminant)
		/ (2.0 * (_this->_equation._c2));
	solution._root2 = (-(_this->_equation._c1) - sqrtDeterminant)
		/ (2.0 * (_this->_equation._c2));
	return solution;
}

