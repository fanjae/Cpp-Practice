#include <iostream>
using namespace std;

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout << "SoComplex Dervied Class" << endl;
	}
};

int main(void)
{
	SoSimple simObj;
	SoSimple& ref = simObj;

	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref); // ref가 참조하는 대상이
		// SoSimple 객체이다. 따라서, SoComplex 참조형으로 형 변환은 안전치않다.
		// 하지만, 참조자를 대상으로는 NULL을 반환할 수 없어, bad_cast 예외가 발생한다.
		comRef.ShowSimpleInfo();
		// 예외로 인해 실행되지 못한다.
	}
	catch (bad_cast expt)
	{
		cout << expt.what() << endl;
		// what 함수는 예외의 원인을 문자열 형태로 반환한다.
	}
	return 0;
}