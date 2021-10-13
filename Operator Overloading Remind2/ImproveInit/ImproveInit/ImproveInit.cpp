#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		cout << "AAA(const AAA& ref)" << endl;
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator = (const AAA& ref)" << endl;
		return *this;
	}
};

class BBB // �̴ϼȶ������� �̿��� ��� �ʱ�ȭ
{
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) { } 
};

class CCC // ���� ������ �̿��� ��� �ʱ�ȭ
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) {
		mem = ref;
	}
};

int main(void)
{
	AAA obj1(12);
	cout << "*****************" << endl;
	BBB obj2(obj1);
	cout << "*****************" << endl;

	// BBB ��ü�� ���� �����ڸ� ȣ��Ǿ���.
	// �̿� �ݸ� CCC ��ü�� �����ڿ� ���� �����ڱ��� ȣ��Ǿ���.
	// �������� ��ü �κп��� ���� ������ ���� �ʱ�ȭ�� �����ϸ�, ����� �ʱ�ȭ�� ���� ������ ���忡�� �����ϴ� ���·� ���̳ʸ� �ڵ尡 �����ȴ�.
	// ����, �̴ϼ� �������� �̿��ؼ� �ʱ�ȭ�� �����ϸ�, �Լ� ȣ��Ƚ���� ���� �� �־, �ʱ�ȭ�� ������ �ܼ�ȭ��Ű�� ���� �����ϴ�.
	CCC obj3(obj1);
	return 0;
}