#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
		{
			throw 0;
		}
		cout << "몫 : " << num1 / num2 << endl;
		cout << "나머지 : " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "first catch" << endl;
		throw; // catch 블록으로 전달된 예외가 소멸되지 않고, 다시 던져짐.
		// 함수를 호출한 영역으로 예외가 전달됨.
	}
}

int main(void)
{
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn) // Divide 함수에 의해서 다시 전달된 예외가 이 catch 블록으로 전달됨.
	{
		cout << "second catch" << endl;
	}
	return 0;
}