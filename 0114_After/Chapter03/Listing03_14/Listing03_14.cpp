#include <iostream>
int main()
{
	using namespace std;
	int auks, bats, coots;

	// ���� ������ �� ���� double������ ���� �� �� ���� int������ ��ȯ�Ͽ� ��������.
	auks = 19.99 + 11.99;

	// ���� �� ������ �� ���� int������ ��ȯ�� �Ŀ� ���Ѵ�.
	bats = (int) 19.99 + (int) 11.99; // C Style
	coots = int(19.99) + int(11.99);  // C++ Style

	cout << "�ٴٿ��� = " << auks << ", ���� = " << bats;
	cout << ", �˵տ��� = " << coots << endl;

	char ch = 'Z';
	cout << "�ڵ� " << ch << " �� ���� ";				// char������ ���
	cout << int(ch) << endl;							// int������ ���
	cout << "��, �ڵ� Z�� ���� ";
	cout << static_cast<int>(ch) << endl;				// int������ ���

	/* static_cast<> �����ڴ� � ��ġ ���������� �ٸ� ��ġ ������������ ��ȯ�ϴµ� ����Ѵ�.
	value�� typeName������ ��ȯ�Ѵ�.
	*/
	return 0;
}