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

};

class private_Derived : private Base
{
	// private 보다 접근의 범위가 넓은 멤버는 protected로 변경시켜서 상속한다.	
};

class protected_Derived : protected Base
{
	// protected 보다 접근의 범위가 넓은 멤버는 protected로 변경시켜서 상속한다.	
};

class public_Derived : public Base
{
	// private을 제외한 나머지는 그대로 상속한다.
};

int main(void)
{

}