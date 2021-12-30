#pragma comment (lib, "./LibTest.lib")

#include <stdio.h>
#include "../LibTest/LibTest.h"
int main(void)
{
	int iNum = Return200();
	printf("iNum : %d\n", iNum);
	return 0;
}