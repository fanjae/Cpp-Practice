#include <iostream>
using namespace std;
int main(void)
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "�����ѷ� " << chest << " (10����) " << endl;
	cout << hex;		// ������ �ٲٴ� ������
	cout << "�㸮�ѷ� " << waist << " (16����)" << endl;
	cout << oct;		// ������ �ٲٴ� ������
	cout << "�νɱ��� " << inseam << " (8����)" << endl;
	return 0;
}

/*
cout << hex;�� ���� ������ ������ ���÷����ϴ� ����� �����Ѵ�.
hex�� std �̸� ������ �Ϻ��̰�, �� ���α׷��� std �̸� ������ ����Ѵ�.
�� ���α׷��� hex�� ���� �̸����� ����� �� ����.
using �����ڸ� �����ϰ�, std::hex�� ����Ѵٸ�, hex�� ������ �̸����� ����� �� �ִ�.
*/
