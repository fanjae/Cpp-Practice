#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << "\n";
	}
	void ShowData() const
	{
		cout << "num : " << num << "\n";
	}
};

void SimpleFunctionObj(SoSimple ob)
{
	ob.ShowData();
}

int main(void)
{
	SoSimple obj(7);
	cout << "�Լ�ȣ�� ��" << "\n";
	SimpleFunctionObj(obj); // �Լ� ȣ�� �� ���ڸ� �����ϴ� �������� ���� �������� ȣ���� Ȯ�� ����
	cout << "�Լ�ȣ�� ��" << "\n";
	return 0;
}
