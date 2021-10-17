#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2)
{
	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)
{
	cout << Add(5, 7) << endl;
	cout << Add(3.7, 7.5) << endl;
	cout << Add<int>(5, 7) << endl; // 일반함수의 존재로 <int> 표시를 통해 템플릿 함수 호출을 명시.
	cout << Add<double>(3.7, 7.5) << endl;

	// 일반적으로 템플릿을 정의한 상황에서 일반함수를 정의하지 않는다.
	// 다만, 컴파일러에 의해서 만들어지는 템플릿 함수가 일반함수와 구분된다.
	return 0;
}