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
	SoSimple *simPtr = new SoComplex; // simPtr이 실제 가리키는 것은 SoComplex 객체이다.
	SoComplex *comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	return 0;
}