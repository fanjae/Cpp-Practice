#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFuncOne()
	{
		cout << "BaseOne" << "\n";
	}
};

class BaseTwo
{
public:
	void SimpleFuncTwo()
	{
		cout << "BaseTwo" << "\n";
	}
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc() // BaseOne 클래스 멤버함수와 BaseTwo 클래스 멤버함수를 각각 호출
	{
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();
}
