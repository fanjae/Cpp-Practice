#include <iostream>
using namespace std;

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "�����ڵ� : " << expn << endl;
	}
	return 0;
}

void SimpleFuncOne(void)
{
	cout << "SimpleFuncOne(void)" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo(void)
{
	cout << "SimpleFuncTwo(Void)" << endl;
	SimpleFuncThree();
}
void SimpleFuncThree(void)
{
	cout << "SimpleFuncThree(void)" << endl;
	// SimpleFuncThree �Լ������� ������ ���ܸ� �߻���Ų��.
	// ���ܸ� ó���ϱ� ���� try~catch�� main �Լ��� ���ǵǾ� �־�, main->SimpleFuncOne->Two->Three ������ ȣ��ǰ�,
	// Three->Two->One->main ������ ���޵ȴ�.
	throw - 1;
}