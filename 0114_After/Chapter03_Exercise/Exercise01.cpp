#include <iostream>
using namespace std;
int main(void)
{
	int height;
	const int Meter = 100;


	cout << "��Ƽ���͸� �Է��ϼ��� : ";
	cin >> height;

	cout << "���� : " << height / Meter << endl;
	cout << "��Ƽ���� : " << height % Meter << endl;

	return 0;
}	