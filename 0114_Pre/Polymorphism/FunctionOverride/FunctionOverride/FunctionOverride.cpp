#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc()
	{
		cout << "First Func" << "\n";
	}
};

class Second : public First
{
public:
	void MyFunc()
	{
		cout << "Second Func" << "\n";
	}
};

class Third : public Second
{
public:
	void MyFunc()
	{
		cout << "Third Func" << "\n";
	}
};

int main(void)
{
	Third *tptr = new Third();
	Second *sptr = tptr;
	First *fptr = sptr;

	fptr->MyFunc(); // First형 포인터 변수를 이용하면 First 클래스에 정의된 MyFunc 함수 호출
	sptr->MyFunc(); // Second형 포인터 변수를 이용하면 Second형 클래스에 정의된 MyFunc 함수 호출
	tptr->MyFunc(); // Third형 포인터 변수를 이용하면 Third형 클래스에 정의된 MyFunc 함수 호출

	// 함수를 오버라이딩 했다는 것은 해당 객체에서 호출되어야 하는 함수를 바꾼다는 것을 의미한다.
	// 하지만, 포인터 변수의 자료형에 따라서 호출되는 함수의 종류가 달라지는 것은 문제가 있지 않은가?
	// 이러한 상황이 발생하지 않도록 하는 것이 Virtual Function 이다. (FunctionVirtualOverride.cpp) 참고

	delete tptr;
	return 0;
}