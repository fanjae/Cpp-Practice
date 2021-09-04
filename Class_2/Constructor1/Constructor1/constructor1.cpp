#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:

	/* �����ڴ� �����ε��� �����ϴ�. */
	SimpleClass()
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}

	void showData() const
	{
		cout << num1 << ' ' << num2 << "\n";
	}
};

int main(void)
{
	SimpleClass sc1; 
	sc1.showData();

	SimpleClass sc2(100); // SimpleClass(int n) ������ ��ü ����
	sc2.showData();

	SimpleClass sc3(100, 200); // SimpleClass(int n1, int n2) ������ ��ü ����
	sc3.showData();

	// SimpleClass sc4(); ������ ���� �����ڸ� �̿��Ͽ� ��ü�� �����ϴ� ���� �Ұ����ϴ�.
	return 0;
}