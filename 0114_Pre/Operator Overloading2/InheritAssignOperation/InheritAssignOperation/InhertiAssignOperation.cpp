#include <iostream>

using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{
	}
	void ShowData()
	{
		cout << num1 << ", " << num2 << "\n";
	}

	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << "\n";
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4)
	{
	}
	void ShowData()
	{
		First::ShowData();
		cout << num3 << ", " << num4 << "\n";
	}

	
	/* 유도 클래스의 대입 연산자 정의에서
	명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않으면, 기초 클래스의 대입연산자는
	호출되지 않아서, 기초 클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외된다. */ 

	/*
	Second& operator=(const Second& ref)
	{
		cout <<	"Second& operator=()" << "\n";
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	} */

	Second& operator=(const Second& ref)
	{
		cout << "Second& operator=()" << "\n";
		First::operator=(ref); // 이와 같이 기초 클래스의 대입 연산자 호출을 명령해야 한다.
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	
};

int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();
	return 0;
}
