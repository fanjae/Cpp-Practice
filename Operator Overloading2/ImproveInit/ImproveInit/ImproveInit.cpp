#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)
	{
		cout << "AAA(int n=0)" << "\n";
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << "\n";
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << "\n";
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) // ��� �̴ϼȶ������� �̿��� ����� �ʱ�ȭ�ϰ� �ִ�.
	{
	}
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) // ���Կ����� �̿��Ͽ� ����� �ʱ�ȭ �ϰ� �ִ�.
	{
		// �������� ��ü �κп��� ���Կ����� ���� �ʱ�ȭ�� �����Ͽ���.
		// ����, �����ڿ� ���� �����ڰ� ���� �ѹ��� ȣ��ȴ�.

		mem = ref;
	}
};

int main(void)
{
	AAA obj1(12);
	cout << "****************************" << "\n";
	// �̴ϼȶ������� �̿��ϸ� ����� ���ÿ� �ʱ�ȭ�� �̷����� ���·�
	// ���̳ʸ� �ڵ尡 �����ȴ�.
	BBB obj2(obj1);
	cout << "****************************" << "\n";
	CCC obj3(obj1);
	return 0;
}