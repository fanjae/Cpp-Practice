#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()
	{
		cout << "First Func" << "\n";
	}
};

class Second : public First
{
public:
	virtual void MyFunc() //7���� MyFunc �Լ��� Virtual�� ����Ǿ� �����Ƿ�, ����� Virtual ������ �����ص� ������ ����.
	{
		cout << "Second Func" << "\n";
	}
};

class Third : public Second
{
public:
	virtual void MyFunc() //7���� MyFunc �Լ��� Virtual�� ����Ǿ� �����Ƿ�, ����� Virtual ������ �����ص� ������ ����.
	{
		cout << "Third Func" << "\n";
	}
};

int main(void)
{
	Third *tptr = new Third();
	Second * sptr = tptr;
	First * fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	// �Լ��� ���� �Լ��� ����Ǹ� �ش� �Լ� ȣ�� ��, �������� �ڷ����� ������� ȣ�� ����� �������� �ʴ´�.
	// ������ ������ ������ ����Ű�� ��ü�� �����Ͽ� ȣ���� ����� �����Ѵ�.
}