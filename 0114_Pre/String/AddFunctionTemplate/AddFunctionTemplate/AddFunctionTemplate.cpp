#include <iostream>
using namespace std;
template <typename T> 
T Add(T num1, T num2)
{
	return num1 + num2;
}

int main(void)
{
	cout << Add<int>(15, 20) << endl; // T를 int로 해서 만들어진 Add 함수를 호출한다.
	cout << Add<double>(2.9, 3.7) << endl;
	// 위 함수를 컴파일러는 아래와 같이 만든다.
	// double Add(double num1, double num2)
	// {
	//		return num1 + num2;
	// }
	// 컴파일 시 함수가 만들어지기 때문에 컴파일 하는데 시간은 늦어질 수 있다.
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;
	return 0;
}