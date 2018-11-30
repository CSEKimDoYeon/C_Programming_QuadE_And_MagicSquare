#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"

#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(MagicSquare* aMagicSquare) { //inputOrder, board
	char messageBuffer[255];
	sprintf(messageBuffer, "> Magic Square Board: Order %2d\n", aMagicSquare->_order);
	AppIO_out(messageBuffer);
	AppIO_out("    "); // 빈칸4 개
	for (int col = 0; col < aMagicSquare->_order; col++) {
		sprintf(messageBuffer, "[%2d] ", col);
		AppIO_out(messageBuffer);
	}
	AppIO_out("\n");
	for (int row = 0; row < aMagicSquare->_order; row++) { // 보드를 초기화 하는 과정.
		printf("[%2d] ", row); //…… // 여기를채우시오
		for (int col = 0; col < aMagicSquare->_order; col++) {
			//printf("%4d", aBoard[row][col]);// 여기를채우시오
			printf("%4d", aMagicSquare->_board[row][col]);
		}
		AppIO_out("\n");
	}
}

int main(void) {
	MagicSquare magicSquare;
	int inputOrder;
	//int board[MAX_ORDER][MAX_ORDER];
	

	AppIO_out("<<< 마방진풀이를시작합니다>>>\n");
	inputOrder = AppIO_in_order(); // 마방진차수를입력받아inputOrder 에저장
	while (inputOrder != END_OF_RUN) { // 차수가-1 이면프로그램종료
		
		MagicSquare_setOrder(&magicSquare, inputOrder);
		
		if (MagicSquare_orderIsValid(&magicSquare)) { // 차수가유효한지검사
			MagicSquare_solve(&magicSquare); // 사용자가 입력한 차수, 99x99 보드
			// 주어진차수의마방진을얻는다
			Main_showBoard(&magicSquare); // 마방진을화면에보여준다
		}
		inputOrder = AppIO_in_order(); // 마방진차수를입력받아inputOrder 에저장
	}
	AppIO_out("\n<<< 마방진풀이를종료합니다>>>\n");
	system("pause");
	return 0;
} // end of main()