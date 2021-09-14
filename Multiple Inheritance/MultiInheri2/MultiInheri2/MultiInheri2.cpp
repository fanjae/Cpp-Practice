#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFunc()
	{
		cout << "BaseOne" << "\n";
	}
};

class BaseTwo
{
public:
	void SimpleFunc()
	{
		cout << "BaseTwo" << "\n";
	}
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void Complexfunc() // 두 클래스에 정의된 멤버함수의 이름이 동일하게 존재한다. 어느 클래스에 정의된 함수의 호출을 원하는지 명시해야 한다.
	{
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{
	MultiDerived mdr; 
	mdr.Complexfunc(); 
	return 0;
}