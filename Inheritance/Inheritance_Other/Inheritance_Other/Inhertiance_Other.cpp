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
	// private ���� ������ ������ ���� ����� protected�� ������Ѽ� ����Ѵ�.	
};

class protected_Derived : protected Base
{
	// protected ���� ������ ������ ���� ����� protected�� ������Ѽ� ����Ѵ�.	
};

class public_Derived : public Base
{
	// private�� ������ �������� �״�� ����Ѵ�.
};

int main(void)
{

}