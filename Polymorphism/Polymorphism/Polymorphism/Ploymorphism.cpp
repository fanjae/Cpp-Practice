#include <iostream>
using namespace std;

class First
{
public:
	virtual void SimpleFunc()
	{
		cout << "First" << "\n";
	}
};

class Second : public First
{
public:
	virtual void SimpleFunc()
	{
		cout << "Second" << "\n";
	}
};

int main(void)
{
	First *ptr = new First();
	ptr->SimpleFunc(); // �Ʒ��� ������ ������ �����Ѵ�.
	delete ptr;

	ptr = new Second();
	ptr->SimpleFunc(); // ���� ������ ������ �����Ѵ�.
	delete ptr;
	return 0;

	// ptr�� ������ ������ �����̳�, ������ ������ �����ϴ� ��ü�� �ڷ����� �ٸ��� ������,
	// �������� �޶�����. C++������ �������� ���̴�.
}

