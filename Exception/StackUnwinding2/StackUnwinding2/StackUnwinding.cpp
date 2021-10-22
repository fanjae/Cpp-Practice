#include <iostream>
using namespace std;

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "예외코드 : " << expn << endl;
	}
	return 0;
}

void SimpleFuncOne(void)
{
	cout << "SimpleFuncOne(void)" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo(void)
{
	cout << "SimpleFuncTwo(Void)" << endl;
	SimpleFuncThree();
}
void SimpleFuncThree(void)
{
	cout << "SimpleFuncThree(void)" << endl;
	// SimpleFuncThree 함수에서는 무조건 예외를 발생시킨다.
	// 예외를 처리하기 위한 try~catch가 main 함수에 정의되어 있어, main->SimpleFuncOne->Two->Three 순으로 호출되고,
	// Three->Two->One->main 순으로 전달된다.
	throw - 1;
}