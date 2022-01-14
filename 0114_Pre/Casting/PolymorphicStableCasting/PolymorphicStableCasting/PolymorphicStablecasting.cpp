#include <iostream>
using namespace std;

class SoSimple // Polymorphic 클래스, ShowSimpleInfo가 가상함수 이므로
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

// Polymorphic 클래스란 하나 이상의 가상함수를 지니는 클래스를 의미함.
// Dynamic_cast 연산자도 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및
// 참조형으로의 변환을 허용한다. 기초 클래스가 Polymorphic 클래스라면 말이다.
class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo() // 이것 역시 가상함수.
	{
		cout << "SoComplex Derived Class " << endl;
	}
};

int main(void)
{
	SoSimple *simPtr = new SoSimple;
	SoComplex *comPtr = dynamic_cast<SoComplex*>(simPtr); // 안정적이지 못한 형 변환이다.
	// dynamic_cast는 위와 같은 경우 NULL 포인터를 반환한다.

	if (comPtr == NULL)
	{
		cout << "형 변환 실패" << endl;
	}
	else
	{
		comPtr->ShowSimpleInfo();
	}
	return 0;
}