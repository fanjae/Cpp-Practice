#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFunc()
	{
		cout << "BaseOne" << "\n";
	}
};

class BaseTwo
{
public:
	void SimpleFunc()
	{
		cout << "BaseTwo" << "\n";
	}
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void Complexfunc() // �� Ŭ������ ���ǵ� ����Լ��� �̸��� �����ϰ� �����Ѵ�. ��� Ŭ������ ���ǵ� �Լ��� ȣ���� ���ϴ��� ����ؾ� �Ѵ�.
	{
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{
	MultiDerived mdr; 
	mdr.Complexfunc(); 
	return 0;
}