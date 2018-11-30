#include <stdio.h> // scanf 함수를 사용하기 위해 선언.
#include "Common.h"
#include "AppIO.h" // AppIO.h에 정의되어 있는 함수를 구현하기 위해서 사용. 

void AppIO_out_msg_startSolvingQuadEquation() { // 시작 메시지 출력
	printf("<<< 이차방적식 풀이를 시작합니다 >>>\n");
}
void AppIO_out_msg_endSolvingQuadEquation() { // 종료 메시지 출력.
	printf("\n<<< 이차방정식 풀이를 종료합니다 >>>\n");
}

Boolean AppIO_in_solvingIsRequested() // 사용자에게 문제 풀이 여부를 입력받는 함수.
{
	char answer;
	printf("\n? 방정식을풀려면'y', 풀이를종료하려면다른아무키나치시오: ");
	char inputLine[255];
	scanf("%s", inputLine);
	// “return” key 로입력완료된한줄을가져온다.
	answer = inputLine[0]; // 문자열의첫번째문자를입력값으로받는다.
	if (answer == 'y')
		return TRUE;
	else
		return FALSE;
}

void AppIO_in_quadEquation(float* p_c0, float* p_c1, float* p_c2) // 상수, 1차, 2차항의 계수를 입력받는 함수.
{
	printf("? 2 차항의계수를입력하시오 :");
	scanf("%f", p_c2);
	printf("? 1 차항의계수를입력하시오 :");
	scanf("%f", p_c1);
	printf("? 상수항의계수를입력하시오 :");
	scanf("%f", p_c0);
}

void AppIO_out_quadEquation(float c0, float c1, float c2) { // 상수, 1차, 2차항의 계수를 출력.
	Boolean aNonZeroTermDoesExist = FALSE;
	printf(">주어진 방정식 : ");
	if (!FloatValueIsZero(c2)) { // 계수가0 인항은출력하지않는다.
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x*x", c2);
	}
	if (!FloatValueIsZero(c1)) { // 계수가0 인항은출력하지않는다.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f) x", c1);
	}
	if (!FloatValueIsZero(c0)) { // 계수가0 인항은출력하지않는다.
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)", c0);
	}
	if (!aNonZeroTermDoesExist) {
		printf("0"); // 모든항의계수가0 이어서, 출력된항이없다.
	}
	printf(" = 0\n");
}

void AppIO_out_msg_determinantIsNegative(float aDeterminant){ // 판별식의 값이 음수이면 에러 메시지를 띄운다.
	printf("[오류] 판별식의 값이 음수이어서, 해가 존재하지 않습니다\n");
	printf("-판별식의값: %f\n", aDeterminant);
}

void AppIO_out_solution(float root1, float root2) { // 이차방정식의 해를 출력한다.
	printf(">방정식의 해는 다음과 같습니다.\n");
	
	if (fabsf(root1) < 0.000001) { // 해가 0인지 판별하고 0일 경우 -0.000000 으로 출력되는것을 방지하기 위한 조건문
		printf("x1 = 0.000000\n");
	}
	else {
		printf("x1 = %f\n", root1); // 만약 0이 아니라면 root1 을 출력한다.
	}

	if (fabsf(root2) < 0.000001) { // 해가 0인지 판별하고 0일 경우 -0.000000 으로 출력되는것을 방지하기 위한 조건문
		printf("x2 = 0.000000\n");
	}
	else {
		printf("x2 = %f\n", root2); // 만약 0이 아니라면 root2 을 출력한다.
	}
}

void AppIO_out_msg_secondOrderTermCoefficientIsZero() { // 2차항의 계수가 0일 경우 에러 메시지를 띄운다.
	printf("[오류] 이차항의 계수가 0이어서, 이차방정식이 아닙니다.\n");
}