#include "QuadEquationProblem.h"

void QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation) { // 객체에게 정보를 제공하는 함수.
	_this->_equation = anEquation;
}

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this) { 
	//가지고있는2차방정식의2 차항이0 인지를판단하여돌려준다
	 
	return FloatValueIsZero(_this->_equation._c2);
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this) { 
	//가지고있는2차방정식의판별식의값이음수인지를판단하여돌려준다
	float determinant = QuadEquationProblem_determinant(_this) ; 
	if (determinant < 0)
		return TRUE;
	else
		return FALSE;
	 
}

/* 객체의 내용이나 행위의 결과를 얻어내는 함수 */

QuadEquation QuadEquationProblem_equation(QuadEquationProblem* _this) {

}

float QuadEquationProblem_determinant(QuadEquationProblem* _this) {
	//가지고있는2차방정식의판별식의값을계산하여돌려준다, D = b^2-4ac
	QuadEquationProblem qeProblem = *_this; 
	
	float determinant = ((qeProblem._equation._c1)*(qeProblem._equation._c1)) 
		- (4 * (qeProblem._equation._c2)*(qeProblem._equation._c0));

	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem* _this) { 
	Solution solution;
	float determinant = QuadEquationProblem_determinant(_this);
	// 객체에게일을시키는쪽(이를테면main()) 에서사용하는함수이지만,
	// 이렇게객체자신도필요하면사용한다.
	float sqrtDeterminant = sqrt(determinant); // <math.h>를반드시include
	solution._root1 = (-(_this->_equation._c1) + sqrtDeterminant)
		/ (2.0 * (_this->_equation._c2));
	solution._root2 = (-(_this->_equation._c1) - sqrtDeterminant)
		/ (2.0 * (_this->_equation._c2));
	return solution;
}

