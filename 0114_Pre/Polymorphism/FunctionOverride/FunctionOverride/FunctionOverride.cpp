#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc()
	{
		cout << "First Func" << "\n";
	}
};

class Second : public First
{
public:
	void MyFunc()
	{
		cout << "Second Func" << "\n";
	}
};

class Third : public Second
{
public:
	void MyFunc()
	{
		cout << "Third Func" << "\n";
	}
};

int main(void)
{
	Third *tptr = new Third();
	Second *sptr = tptr;
	First *fptr = sptr;

	fptr->MyFunc(); // First�� ������ ������ �̿��ϸ� First Ŭ������ ���ǵ� MyFunc �Լ� ȣ��
	sptr->MyFunc(); // Second�� ������ ������ �̿��ϸ� Second�� Ŭ������ ���ǵ� MyFunc �Լ� ȣ��
	tptr->MyFunc(); // Third�� ������ ������ �̿��ϸ� Third�� Ŭ������ ���ǵ� MyFunc �Լ� ȣ��

	// �Լ��� �������̵� �ߴٴ� ���� �ش� ��ü���� ȣ��Ǿ�� �ϴ� �Լ��� �ٲ۴ٴ� ���� �ǹ��Ѵ�.
	// ������, ������ ������ �ڷ����� ���� ȣ��Ǵ� �Լ��� ������ �޶����� ���� ������ ���� ������?
	// �̷��� ��Ȳ�� �߻����� �ʵ��� �ϴ� ���� Virtual Function �̴�. (FunctionVirtualOverride.cpp) ����

	delete tptr;
	return 0;
}