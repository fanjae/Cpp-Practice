#include <iostream>
using namespace std;

class AAA
{
private:
	int num1;
public:
	virtual void Func1()
	{
		cout << "Func1" << "\n";
	}
	virtual void Func2()
	{
		cout << "Func2" << "\n";
	}
};

class BBB : public AAA
{
private:
	int num2;
public:
	virtual void Func1()
	{
		cout << "BBB::Func1" << "\n";
	}
	void Func3()
	{
		cout << "Func3" << "\n";
	}
};

int main(void)
{
	AAA * aptr = new AAA();
	aptr->Func1();

	BBB * bptr = new BBB();
	bptr->Func1();
	return 0;

	/* �����Լ��� �����ϴ� Ŭ������ ���ؼ��� �����Ϸ���
	'�����Լ� ���̺�'�̶� ���� �����.
	�̴�, ���� ȣ��Ǿ�� �� �Լ��� ��ġ������ ��� �ִ� ���̺��̴�.

	�����Լ� ���̺��� key,value�� �����Ǿ��ְ�,
	key�� ȣ���ϰ��� �ϴ� �Լ��� �����ϴ� �������� ������, value��
	�����ڿ� �ش��ϴ� �Լ��� �ּ������� �˷��ִ� ������ �Ѵ�.

	����, AAA Func1 �Լ��� ȣ���� ���,
	�ش� key�� ���� AAA ��ü�� Func1�Լ��� ȣ���ϴ� ���̰�,
	
	BBB Func1 Ŭ������ �����Լ� ���̺�����
	AAA Ŭ������ �������̵� �� �����Լ� Func1�� ���� ������ �������� �ʴ´�.

	��, �������̵� �� �����Լ��� �ּ������� ���� Ŭ������ �����Լ� ���̺� ���Ե��� �ʴ´�.
	������ �������̵� �� �����Լ��� ȣ���ϸ�, ������ ���� �������� �������̵��� �� ���� Ŭ������ ����Լ��� ȣ��ȴ�.

	*/
}
