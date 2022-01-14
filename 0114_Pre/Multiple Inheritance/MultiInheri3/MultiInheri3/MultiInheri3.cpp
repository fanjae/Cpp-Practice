#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base Constructor" << "\n";
	}
	void SimpleFunc()
	{
		cout << "BaseOne" << "\n";
	}
};

class MiddleDerivedOne : virtual public Base // ���� ���
{
public:
	MiddleDerivedOne() : Base()
	{
		cout << "MiddleDerivedOne Constructor" << "\n";
	}
	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDerivedOne" << "\n";
	}
};

class MiddleDerivedTwo : virtual public Base // ���� ���
{
public:
	MiddleDerivedTwo() : Base()
	{
		cout << "MiddleDerviedTwo Constructor" << "\n";
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDerivedTwo" << "\n";
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo 
{
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		cout << "LastDerived Constructor" << "\n";
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void)
{
	cout << "��ü���� �� ..... " << "\n";
	LastDerived ldr;
	cout << "��ü���� �� ..... " << "\n";
	ldr.ComplexFunc();
	return 0;

	// �� �������� LastDerived�� Base Ŭ������ �ι� ����ϰ� �Ǵµ�, �̶� Base Ŭ������ �� �ѹ��� ����ϰԲ� ������ �Ѵ�.
	// �̸� ���� ������ ���� ����̴�.
	// �������� Base Ŭ������ ����ϴ� �� Ŭ������ �������� ����ϸ�, LastDerived ��ä ���� MiddleDerivedOne Ŭ������
	// MiddleDerivedTwo Ŭ������ ���ÿ� ����ϴ� Base Ŭ������ ����� �ϳ����� �����ϰ� �ȴ�.
	// ���� �������� ���� Base Ŭ������ �����ڰ� �ѹ��� ȣ��ȴ�.
}