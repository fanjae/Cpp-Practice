#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << "\n";
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << "\n";
	}
	void ShowBaseData()
	{
		cout << baseNum << "\n";
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30) // �� �����ڿ����� ���� Ŭ������ ���� ������ �������� ������ Ȯ���� �� �ִ�. �̴� 32�൵ �����ϴ�.
	{
		cout << "SoDerived()" << "\n";
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived(int n)" << "\n";
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) // �� �����ڸ�, ���� Ŭ������ ������ ȣ���� ����Ѵ�.
	{
		cout << "SoDerived(int n1, int n2)" << "\n";
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << "\n";
	}
};

int main(void)
{
	cout << "case1..... " << "\n"; // �����ϸ� ���� Ŭ������ ��ü���� �������� �����ڰ� �ι� �����ȴ�. (���� ������ �� ���� Ŭ���� ������)
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "---------------------" << "\n";
	cout << "case2..... " << "\n";
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "---------------------" << "\n";
	cout << "case3..... " << "\n";
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	return 0;
}