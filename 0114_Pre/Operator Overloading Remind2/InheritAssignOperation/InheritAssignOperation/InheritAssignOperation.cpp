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
		cout << num1 << ", " << num2 << endl;
	}
	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << endl;
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
	Second(int n1, int n2, int n3, int n4)
		: First(n1, n2), num3(n3), num4(n4)
	{
	}
	void ShowData()
	{
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}

	/*
	아래 문장과 같이 실행할 경우,
	기초 캘르스의 대입 연산자 호출문이 존재하지 않아서,
	// 기초 클래스의 멤버 변수는 멤버 대 멤버의 복사 대상에서 제외된다.
	Second& operator=(const Second& ref)
	{
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}*/
	
	Second& operator=(const Second& ref)
	{
		cout << "Second& operator=()" << endl;
		First::operator=(ref); // 기초 클래스의 대입 연산자 호출을 명령
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