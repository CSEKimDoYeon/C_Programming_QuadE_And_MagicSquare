#include "Common.h"
#include "MagicSquare.h"
#include "AppIO.h"

#include <stdio.h>

#define END_OF_RUN -1

void Main_showBoard(MagicSquare* aMagicSquare) { //inputOrder, board
	char messageBuffer[255];
	sprintf(messageBuffer, "> Magic Square Board: Order %2d\n", aMagicSquare->_order);
	AppIO_out(messageBuffer);
	AppIO_out("    "); // ��ĭ4 ��
	for (int col = 0; col < aMagicSquare->_order; col++) {
		sprintf(messageBuffer, "[%2d] ", col);
		AppIO_out(messageBuffer);
	}
	AppIO_out("\n");
	for (int row = 0; row < aMagicSquare->_order; row++) { // ���带 �ʱ�ȭ �ϴ� ����.
		printf("[%2d] ", row); //���� // ���⸦ä��ÿ�
		for (int col = 0; col < aMagicSquare->_order; col++) {
			//printf("%4d", aBoard[row][col]);// ���⸦ä��ÿ�
			printf("%4d", aMagicSquare->_board[row][col]);
		}
		AppIO_out("\n");
	}
}

int main(void) {
	MagicSquare magicSquare;
	int inputOrder;
	//int board[MAX_ORDER][MAX_ORDER];
	

	AppIO_out("<<< ������Ǯ�̸������մϴ�>>>\n");
	inputOrder = AppIO_in_order(); // �������������Է¹޾�inputOrder ������
	while (inputOrder != END_OF_RUN) { // ������-1 �̸����α׷�����
		
		MagicSquare_setOrder(&magicSquare, inputOrder);
		
		if (MagicSquare_orderIsValid(&magicSquare)) { // ��������ȿ�����˻�
			MagicSquare_solve(&magicSquare); // ����ڰ� �Է��� ����, 99x99 ����
			// �־��������Ǹ���������´�
			Main_showBoard(&magicSquare); // ��������ȭ�鿡�����ش�
		}
		inputOrder = AppIO_in_order(); // �������������Է¹޾�inputOrder ������
	}
	AppIO_out("\n<<< ������Ǯ�̸������մϴ�>>>\n");
	system("pause");
	return 0;
} // end of main()