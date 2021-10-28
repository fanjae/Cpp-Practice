#include <iostream>
using namespace std;

void ShowString(char * str)
{
	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2)
{
	cout << n1 + n2 << endl;
}

int main(void)
{
	const char *name = "Lee Sung Ju";
	ShowString(const_cast<char *>(name));
	// const_cast 연산을 통해 함수 인자 전달시 const 선언으로 인한 형(type)의 불일치가 발생해서
	// 인자의 전달이 불가능한 경우 유용하게 사용이 가능하다.

	const int &num1 = 100;
	const int &num2 = 200;
	ShowAddResult(const_cast<int &>(num1), const_cast<int &>(num2));
	return 0;
}