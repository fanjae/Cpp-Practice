#include <iostream>
#include <functional>

void addAndPrint(int a, int b)
{
	int sum = a + b;
	std::cout << sum << "\n";
}
class A
{
public:
	void addAndPrint(int a, int b)
	{
		int sum = a + b;
		std::cout << "sum : " << sum << "\n";
	}
};

A test;
// class의 멤버함수를 가르키고 싶으면, 멤버함수를 위해서
// 어떤 낵체의 멤버함수를 실행할 지 알 수 있도록 객체를 전달해야한다.
std::function<void(int, int)> func1 = addAndPrint;
std::function<void(A&,int, int)> func2 = &A::addAndPrint;

// 멤버함수의 경우엔 함수의 주소값으로 암시적 형변환이 되지 않아서
// 명시적으로 &를 사용해서 주소값을 전달해줘야 한다.

int main()
{
	addAndPrint(10, 20);
	func1(10, 20);
	func3(test, 10, 20);
}