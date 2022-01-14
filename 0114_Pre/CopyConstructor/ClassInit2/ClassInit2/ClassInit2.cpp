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
	/* �Ϲ������δ� ���� �����ڰ� �ڵ����� ���Եȴ�. 
	*/
	explicit SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "CAlled SoSimple(SoSimple &copy)" << "\n";
	}
	void ShowSimpleData() const
	{
		cout << num1 << "\n";
		cout << num2 << "\n";
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << "\n";
	SoSimple sim2(sim1); // explicit�� ����ϸ� SoSimple sim2=sim1�� ���������� ��ȯ�ϴ� ���� ���ġ �ʴ´�.
	// SoSimple sim2 = sim1; (Compile Error)
	cout << "���� �� �ʱ�ȭ ����" << "\n";
	sim2.ShowSimpleData();
	return 0;
}