#include <iostream>

using namespace std;

class First
{
private:
	char *strOne;
public:
	First(const char *str)
	{
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First() // �Ҹ��ڰ� �����ϰ� ���ǵǾ� �ִ�.
	{
		cout << "~First()" << "\n";
		delete[]strOne;
	}
};

class Second : public First
{
private:
	char *strTwo;
public:
	Second(const char *str1, const char *str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	virtual ~Second() // �Ҹ��ڰ� �����ϰ� ���ǵǾ� �ִ�.
	{
		cout << "~Second()" << "\n";
		delete[] strTwo;
	}
};

int main(void)
{
	First *ptr = new Second("simple", "complex");
	delete ptr;

	// ���� ���� ���� �Ҹ��ڰ� ȣ��Ǹ�, ����� ���� ������ �� �Ʒ��� �����ϴ� ���� Ŭ������ �Ҹ��ڰ� ��� ȣ��ȴ�.
	// �׷��鼭, ���� Ŭ������ �Ҹ��ڰ� ���������� ȣ��ȴ�.
	return 0;
}
