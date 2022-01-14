#include <iostream>
using namespace std;

class First
{
public:
	virtual void SimpleFunc()
	{
		cout << "First" << "\n";
	}
};

class Second : public First
{
public:
	virtual void SimpleFunc()
	{
		cout << "Second" << "\n";
	}
};

int main(void)
{
	First *ptr = new First();
	ptr->SimpleFunc(); // 아래에 동일한 문장이 존재한다.
	delete ptr;

	ptr = new Second();
	ptr->SimpleFunc(); // 위에 동일한 문제가 존재한다.
	delete ptr;
	return 0;

	// ptr은 동일한 포인터 변수이나, 포인터 변수가 참조하는 객체의 자료형이 다르기 때문에,
	// 실행결과가 달라진다. C++에서의 다형성의 예이다.
}

