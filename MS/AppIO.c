#include "AppIO.h"
#include <stdio.h>

void AppIO_out(char* aMessage) { 
	printf(aMessage);
}

int AppIO_in_order(void) { 
	int a;
	printf("\n? ������ ������ �Է��Ͻÿ�:");
	scanf("%d", &a);
	return a;
}