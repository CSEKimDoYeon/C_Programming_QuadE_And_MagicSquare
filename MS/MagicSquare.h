#include "Common.h"

void MagicSquare_setOrder(MagicSquare* _this, int newOrder); // 객체의 속성값을 설정하는 함수.
int MagicSquare_order(MagicSquare* _this); // 객체의 속성값을 얻는 함수.

Boolean MagicSquare_orderlsValid(MagicSquare* _this); // 객체의 상태를 검사하는 함수.
void MagicSquare_solve(MagicSquare* _this);