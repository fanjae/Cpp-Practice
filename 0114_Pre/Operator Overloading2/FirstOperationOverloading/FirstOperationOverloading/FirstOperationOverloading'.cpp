#include <iostream>
using namespace std;

class First // 별도의 대입 연산자를 오버로딩 하지 않음
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{

	}
	void ShowData() {
		cout << num1 << ", " << num2 << "\n";
	}

};

class Second // 멤버 대 멤버의 복사가 진행되도록 오버로딩을 진행함.
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{
	}
	void ShowData() {
		cout << num3 << ", " << num4 << "\n";
	}

	Second& operator=(const Second& ref)
	{
		cout << "Second& operator=()" << "\n"; // 대입 연산자 호출 여부를 확인한다.
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;

	fcpy = fsrc; // fcpy.operator=(fsrc)
	scpy = ssrc; // scpy.operator=(ssrc)

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
	return 0;
}