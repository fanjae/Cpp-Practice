#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2; //  const �Լ� �������� ���� ������ ���������� ����Ѵ�.
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{
	}
	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << "\n";
	}
	void CopyTopNum2() const
	{
		num2 = num1; // num2�� ���� ����� �� �ִ� ������ num2�� mutable�� ����Ǿ� �ֱ� �����̴�.
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyTopNum2();
	sm.ShowSimpleData();
	return 0;
}