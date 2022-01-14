#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc()
	{
		cout << "FirstFunc()" << "\n";
	}
	virtual void SimpleFunc()
	{
		cout << "First's SimpleFunc()" << "\n";
	}
};

class Second : public First
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << "\n";
	}
	virtual void SimpleFunc()
	{
		cout << "Second's SimpleFunc()" << "\n";
	}
};

class Third : public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << "\n";
	}
	virtual void SimpleFunc()
	{
		cout << "Third's SimpleFunc()" << "\n";
	}
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second &sref=obj; // obj는 Second를 상속하는 Third 객체이므로, Second형 참조자로 사용 가능하다.
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();
	/* 컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성을 판단한다.
	First 클래스에 정의된 FirstFunc와 Second 클래스에 정의된 SecondFunc()는 호출이 가능하다.
	하지만 ThirdFunc 함수는 호출이 불가능하다. */

	First &fref=obj;
	fref.FirstFunc();
	fref.SimpleFunc();

	return 0;

}