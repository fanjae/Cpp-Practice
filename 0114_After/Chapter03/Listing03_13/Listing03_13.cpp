#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);

	float tree = 3;			// int���� float������ ��ȯ
	int guess = 3.9832;		// float���� int������ ��ȯ
	int debt = 7.2E12;		// ��� ���� �Ұ�

	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	return 0;

}

/* ������ ������ �ε� �Ҽ����� ������ �ʱ�ȭ�� ��� �����Ͱ� �սǵ� �� �ִ�.
debt�� ����ϴ� ���� �����Ϸ����� �ٸ���.
*/