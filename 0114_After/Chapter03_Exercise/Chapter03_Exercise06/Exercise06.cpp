#include <iostream>
using namespace std;
int main(void)
{
	double go_distance;
	double go_gas;

	cout << "������ �Ÿ��� ���� ������ �Է��ϼ��� : ";
	cin >> go_distance;

	cout << "�Һ��� �ֹ����� ���� ���� ������ �Է��ϼ��� : ";
	cin >> go_gas;

	cout << "������ ���� �� : " << go_distance / go_gas << endl << endl;

	cout << "==== ���� Ver(100ų�ι��ʹ� ���� ��) ====" << endl;
	cout << "������ �Ÿ��� ų�ι��� ������ �Է��ϼ��� : ";
	cin >> go_distance;

	cout << "�Һ��� �ֹ����� ���� ���� ������ �Է��ϼ��� : ";
	cin >> go_gas;
	cout << "100ų�ι��ʹ� ���� �� : " << (go_gas / go_distance) * 100 << endl;
	
}