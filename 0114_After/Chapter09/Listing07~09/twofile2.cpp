#include <iostream>
extern int tom;					// tom�� �ٸ� ���Ͽ� ����
static int dick = 10;			// �ܺ� dick�� ���� ����.
int harry = 200;				// �ܺ� ���� ����
								// twofile1.cpp�� harry�� �浹���� ����.
void remote_access()
{
	using namespace std;
	cout << "remote_access()�� �����ϴ� �� ������ �ּ� : \n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
}