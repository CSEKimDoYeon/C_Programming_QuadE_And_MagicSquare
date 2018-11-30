#include <math.h>

#include "Common.h"
#include "AppIO.h"
#include "QuadEquationProblem.h"

int main()
{
	QuadEquationProblem qeProblem; // 이차방정식 객체생성.
	Boolean solvingIsRequested; // 사용자가 y를 입력하여 문제풀이를 요청했는지의 여부.
	QuadEquation equation; // 이차방정식 equation.
	Solution solution; // 이차방정식의 해를 가지고 있는 객체.

	AppIO_out_msg_startSolvingQuadEquation(); // "이차방정식 풀이를 시작합니다."
	solvingIsRequested = AppIO_in_solvingIsRequested(); // "방정식을 풀려면 y 입력."

	while (solvingIsRequested) { // solvingIsRequested가 y여서 true 일 때 까지.
		AppIO_in_quadEquation(&equation._c0, &equation._c1, &equation._c2); // 상수항, 1차항, 2차항 입력
		
		QuadEquationProblem_setEquation(&qeProblem, equation); // qeProblem 구조체의 주소로 접근하여 equation을 적용해준다.

		AppIO_out_quadEquation(equation._c0, equation._c1, equation._c2); // 상수항, 1차항, 2차항 출력

		
		if (QuadEquationProblem_secondOrderTermCoefficientIsZero(&qeProblem)) {
			AppIO_out_msg_secondOrderTermCoefficientIsZero(); // 2차항의 계수가 0인지 판별.
		}
		else {
			if (QuadEquationProblem_determinantIsNegative(&qeProblem)) { // 판별식이 0 이하인지 판별.
				float determinant = QuadEquationProblem_determinant(&qeProblem);
				AppIO_out_msg_determinantIsNegative(determinant); // 판별식이 0 이하이면 오류메시지 출력.
			}
			else {
				solution = QuadEquationProblem_solve(&qeProblem); // 이차방정식의 해를 solution 객체에 저장.
				AppIO_out_solution(solution._root1, solution._root2); // solution 객체에 들어있는 x1, x2 값을 출력.
			}
		}
		solvingIsRequested = AppIO_in_solvingIsRequested(); 
	}
	AppIO_out_msg_endSolvingQuadEquation(); // y를 입력하지 않았을 경우 종료 메시지 출력.

	system("pause"); // 프로그램이 자동 종료되지 않도록 하는 코드. 일시정지
	return 0;
}