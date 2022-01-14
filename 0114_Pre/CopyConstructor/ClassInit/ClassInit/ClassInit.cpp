#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{

	}
	SoSimple(SoSimple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "CAlled SoSimple(SoSimple &copy)" << "\n";
	}
	void ShowSimpleData()
	{
		cout << num1 << "\n";
		cout << num2 << "\n";
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << "\n";
	SoSimple sim2 = sim1; // SoSimple sim2(sim1); ���� ��ȯ�Ͽ� 15�࿡ ���ǵ� �����ڰ� ȣ��ȴ�.
	//���� ���� 15�࿡ ���ǵ� �����ڸ� ���� ������(Copy constructor)�� �Ѵ�.
	cout << "���� �� �ʱ�ȭ ����" << "\n";
	sim2.ShowSimpleData();
	return 0;
}