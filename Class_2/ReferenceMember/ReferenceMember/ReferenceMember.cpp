#include <iostream>
using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object " << "\n";
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA &ref;
	const int &num;
public:
	// �̴ϼȶ����������� ��������� �����ڸ� ������ �� �ְ� �Ѵ�.
	BBB(AAA &r, const int &n) : ref(r), num(n)
	{

	}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << "\n";
		cout << "I ref num " << num << "\n";
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}