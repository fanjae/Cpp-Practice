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
	~First() // 소멸자가 적절하게 정의되어 있다.
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
	Second(const char *str1,const char *str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second() // 소멸자가 적절하게 정의되어 있다.
	{
		cout << "~Second()" << "\n";
		delete[] strTwo;
	}
};

int main(void)
{
	First *ptr = new Second("simple", "complex");
	delete ptr;

	// 위와 같은 First 클래스의 소멸자만 호출되었다.
	// 이러한 경우 메모리의 누수가 발생한다.
	return 0;
}
