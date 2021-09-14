#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base Constructor" << "\n";
	}
	void SimpleFunc()
	{
		cout << "BaseOne" << "\n";
	}
};

class MiddleDerivedOne : virtual public Base // 가상 상속
{
public:
	MiddleDerivedOne() : Base()
	{
		cout << "MiddleDerivedOne Constructor" << "\n";
	}
	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDerivedOne" << "\n";
	}
};

class MiddleDerivedTwo : virtual public Base // 가상 상속
{
public:
	MiddleDerivedTwo() : Base()
	{
		cout << "MiddleDerviedTwo Constructor" << "\n";
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDerivedTwo" << "\n";
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo 
{
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		cout << "LastDerived Constructor" << "\n";
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void)
{
	cout << "객체생성 전 ..... " << "\n";
	LastDerived ldr;
	cout << "객체생성 후 ..... " << "\n";
	ldr.ComplexFunc();
	return 0;

	// 위 예제에서 LastDerived는 Base 클래스를 두번 상속하게 되는데, 이때 Base 클래스를 딱 한번만 상속하게끔 만들어야 한다.
	// 이를 위한 문법이 가상 상속이다.
	// 가상으로 Base 클래스를 상속하는 두 클래스를 다중으로 상속하면, LastDerived 객채 내의 MiddleDerivedOne 클래스와
	// MiddleDerivedTwo 클래스가 동시에 상속하는 Base 클래스의 멤버가 하나씩만 존재하게 된다.
	// 실제 실행결과를 보면 Base 클래스의 생성자가 한번만 호출된다.
}