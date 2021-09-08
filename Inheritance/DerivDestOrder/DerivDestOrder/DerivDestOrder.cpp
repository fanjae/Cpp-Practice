#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase() : " << baseNum << "\n";
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << "\n";
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << "\n";
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << "\n";
	}
};

int main(void)
{
	SoDerived drv1(15);
	SoDerived drv2(27);

	// ���� Ŭ������ ��ü�� �Ҹ�ɶ��� ���� Ŭ������ �Ҹ��ڰ� ���� ����ǰ� �� ������
	// ���� Ŭ������ �Ҹ��ڰ� ����ȴ�.
	// ���ÿ� ������ ��ü�� �Ҹ� ������ ���������� �ݴ��̴�.
	return 0;
}