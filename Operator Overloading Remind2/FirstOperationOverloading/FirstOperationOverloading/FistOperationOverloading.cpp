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
	// First 클래스는 대입 연산자 별도 오버로딩을 하지 않음.
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{
	}
	void ShowData()
	{
		cout << num3 << ", " << num4 << endl;
	}

	Second& operator=(const Second& ref)
	{
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;

		// 멤버 대 멤버 복사.
	}
};

int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc; // fcpy.operator =(fsrc);

	// 별도로 추가하진 않았지만 first 클래스에 자동으로 삽입된 디폴트 대입 연산자가 존재한다.

	/*
	First& operator=(const First& ref)
	{
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
	*/

	scpy = ssrc; // scpy.operator =(ssrc);
	
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
}

