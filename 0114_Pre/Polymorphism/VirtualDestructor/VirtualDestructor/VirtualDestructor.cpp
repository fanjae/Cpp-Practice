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
	~First() // �Ҹ��ڰ� �����ϰ� ���ǵǾ� �ִ�.
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
	Second(const char *str1,const char *str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second() // �Ҹ��ڰ� �����ϰ� ���ǵǾ� �ִ�.
	{
		cout << "~Second()" << "\n";
		delete[] strTwo;
	}
};

int main(void)
{
	First *ptr = new Second("simple", "complex");
	delete ptr;

	// ���� ���� First Ŭ������ �Ҹ��ڸ� ȣ��Ǿ���.
	// �̷��� ��� �޸��� ������ �߻��Ѵ�.
	return 0;
}
