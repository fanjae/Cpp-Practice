#include <iostream>
using namespace std;
int main(void)
{
	long long world_people;
	long long usa_people;

	cout << "���� �α����� �Է��Ͻÿ�: ";
	cin >> world_people;
	cout << "�̱��� �α����� �Է��Ͻÿ�: ";
	cin >> usa_people;

	cout << "���� �α������� �̱��� �����ϴ� ������ " << double (usa_people) / double(world_people) * 100 << "%�̴�." << endl;
	return 0;
}