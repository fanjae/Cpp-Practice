#include <iostream>
using namespace std;

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout << "SoComplex Dervied Class" << endl;
	}
};

int main(void)
{
	SoSimple simObj;
	SoSimple& ref = simObj;

	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref); // ref�� �����ϴ� �����
		// SoSimple ��ü�̴�. ����, SoComplex ���������� �� ��ȯ�� ����ġ�ʴ�.
		// ������, �����ڸ� ������δ� NULL�� ��ȯ�� �� ����, bad_cast ���ܰ� �߻��Ѵ�.
		comRef.ShowSimpleInfo();
		// ���ܷ� ���� ������� ���Ѵ�.
	}
	catch (bad_cast expt)
	{
		cout << expt.what() << endl;
		// what �Լ��� ������ ������ ���ڿ� ���·� ��ȯ�Ѵ�.
	}
	return 0;
}