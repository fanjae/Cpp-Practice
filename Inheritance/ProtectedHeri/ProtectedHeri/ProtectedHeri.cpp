#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3)
	{
	}
};

class Derived : protected Base
{

};

int main(void)
{
	Derived drv;
	cout << drv.num3 << "\n"; // Compile Error 발생
	// Base 클래스를 상속할 때 Protected로 상속했기 때문에
	// public 멤버변수인 num3는 Derived 클래스에서 protected 멤버가 된다.
	return 0;
}