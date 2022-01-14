#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()
	{
		cout << "First Func" << "\n";
	}
};

class Second : public First
{
public:
	virtual void MyFunc() //7행의 MyFunc 함수가 Virtual로 선언되어 있으므로, 여기는 Virtual 선언을 생략해도 문제는 없다.
	{
		cout << "Second Func" << "\n";
	}
};

class Third : public Second
{
public:
	virtual void MyFunc() //7행의 MyFunc 함수가 Virtual로 선언되어 있으므로, 여기는 Virtual 선언을 생략해도 문제는 없다.
	{
		cout << "Third Func" << "\n";
	}
};

int main(void)
{
	Third *tptr = new Third();
	Second * sptr = tptr;
	First * fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	// 함수가 가상 함수로 선언되면 해당 함수 호출 시, 포인터의 자료형을 기반으로 호출 대상을 결정하지 않는다.
	// 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정한다.
}