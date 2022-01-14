#include <iostream>

using namespace std;

class First
{
private:
	char *strOne;
public:
	First(const char *str)
	{
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First() // 소멸자가 적절하게 정의되어 있다.
	{
		cout << "~First()" << "\n";
		delete[]strOne;
	}
};

class Second : public First
{
private:
	char *strTwo;
public:
	Second(const char *str1, const char *str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	virtual ~Second() // 소멸자가 적절하게 정의되어 있다.
	{
		cout << "~Second()" << "\n";
		delete[] strTwo;
	}
};

int main(void)
{
	First *ptr = new Second("simple", "complex");
	delete ptr;

	// 위와 같이 가상 소멸자가 호출되면, 상속의 계층 구조상 맨 아래에 존재하는 유도 클래스의 소멸자가 대신 호출된다.
	// 그러면서, 기초 클래스의 소멸자가 순차적으로 호출된다.
	return 0;
}
