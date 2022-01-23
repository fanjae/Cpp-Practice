#include <iostream>
const int ArSize = 16; // 외부 선언의 예시
int main()
{
	long long factorials[ArSize]; 
	factorials[1] = factorials[0] = 1LL;

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ArSize; i++)
		std::cout << i << "! = " << factorials[i] << std::endl;
	return 0;
}
/* 본 프로그램의 경우 20!을 표현하고 싶은 경우
ArSize = 20만 수정하면 된다. */