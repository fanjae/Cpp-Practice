#include <iostream>
using namespace std;

class AAA
{
private:
	int num1;
public:
	virtual void Func1()
	{
		cout << "Func1" << "\n";
	}
	virtual void Func2()
	{
		cout << "Func2" << "\n";
	}
};

class BBB : public AAA
{
private:
	int num2;
public:
	virtual void Func1()
	{
		cout << "BBB::Func1" << "\n";
	}
	void Func3()
	{
		cout << "Func3" << "\n";
	}
};

int main(void)
{
	AAA * aptr = new AAA();
	aptr->Func1();

	BBB * bptr = new BBB();
	bptr->Func1();
	return 0;

	/* 가상함수를 포함하는 클래스에 대해서는 컴파일러가
	'가상함수 테이블'이란 것을 만든다.
	이는, 실제 호출되어야 할 함수의 위치정보를 담고 있는 테이블이다.

	가상함수 테이블은 key,value로 구성되어있고,
	key는 호출하고자 하는 함수를 구분하는 구분자의 역할을, value는
	구분자에 해당하는 함수의 주소정보를 알려주는 역할을 한다.

	만약, AAA Func1 함수를 호출할 경우,
	해당 key에 따라서 AAA 객체의 Func1함수를 호출하는 것이고,
	
	BBB Func1 클래스의 가상함수 테이블에서는
	AAA 클래스의 오버라이딩 된 가상함수 Func1에 대한 정보가 존재하지 않는다.

	즉, 오버라이딩 된 가상함수의 주소정보는 유도 클래스의 가상함수 테이블에 포함되지 않는다.
	때문에 오버라이딩 된 가상함수를 호출하면, 무조건 가장 마지막에 오버라이딩을 한 유도 클래스의 멤버함수가 호출된다.

	*/
}
