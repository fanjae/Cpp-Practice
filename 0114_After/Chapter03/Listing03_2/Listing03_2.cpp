#include <iostream>
#define ZERO 0		// �� 0���� ��ü�� ��ȣ ��� ZERO�� ����
#include <climits>	// INT_MAX�� int���� �ִ밪���� ����
int main()
{
	using namespace std;
	short Dohee = SHRT_MAX;
	unsigned short Insuk = Dohee;

	cout << "������ ���¿��� " << Dohee << "���� ��� �ְ�, ";
	cout << "�μ����� ���¿��� " << Insuk << "���� ��� �ִ�." << endl;
	cout << "������ ���¿� 1���� �Ա��Ѵ�." << endl << "���� ";
	Dohee = Dohee + 1;
	Insuk = Insuk + 1;
	cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << Insuk << "���� �Ǿ���." << endl;
	cout << "�̷� ����! ���� �� ���� ������ �߳�?" << endl << endl;

	Dohee = ZERO;
	Insuk = ZERO;
	cout << "������ ���¿��� " << Dohee << "���� ��� �ְ�, ";
	cout << "�μ����� ���¿��� " << Insuk << "���� ��� �ִ�." << endl;
	cout << "������ ���¿� 1���� �Ա��Ѵ�." << endl << "���� ";

	Dohee = Dohee + 1;
	Insuk = Insuk + 1;
	cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << Insuk << "���� �Ǿ���." << endl;
	cout << "�̷� ����! �μ��̰� ���ǿ� ��÷�Ǿ���?" << endl << endl;
	return 0;
}

/* short ���� �ִ� �� 32,767(�� �ý��� ����) Insuk ������ +1�� �ص� �������� ����.
�ִ밪�� 65,535���� �۴�. ������ Dohee�� 32,767dptj -32,768�� ���ڱ� �Ѿ��.
unsigned short ���� Insuk���� 1�� ���� 0���� 65,535�� ���ڱ� �Ѿ��.

��, ǥ���� �� �ִ� �Ѱ踦 ����� �� ǥ�� ������ �ݴ��������� �ٽ� �����Ѵ�. */
