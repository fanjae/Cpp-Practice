#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc()
	{
		cout << "FirstFunc()" << "\n";
	}
	virtual void SimpleFunc()
	{
		cout << "First's SimpleFunc()" << "\n";
	}
};

class Second : public First
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << "\n";
	}
	virtual void SimpleFunc()
	{
		cout << "Second's SimpleFunc()" << "\n";
	}
};

class Third : public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << "\n";
	}
	virtual void SimpleFunc()
	{
		cout << "Third's SimpleFunc()" << "\n";
	}
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second &sref=obj; // obj�� Second�� ����ϴ� Third ��ü�̹Ƿ�, Second�� �����ڷ� ��� �����ϴ�.
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();
	/* �����Ϸ��� �������� �ڷ����� ������ �Լ��� ȣ�� ���ɼ��� �Ǵ��Ѵ�.
	First Ŭ������ ���ǵ� FirstFunc�� Second Ŭ������ ���ǵ� SecondFunc()�� ȣ���� �����ϴ�.
	������ ThirdFunc �Լ��� ȣ���� �Ұ����ϴ�. */

	First &fref=obj;
	fref.FirstFunc();
	fref.SimpleFunc();

	return 0;

}