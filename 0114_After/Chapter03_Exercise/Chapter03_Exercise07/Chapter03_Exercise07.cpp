#include <iostream>
using namespace std;
int main(void)
{
	double gas_europe;
	cout << "�ֹ��� �Һ��� �ۼ��ϼ���(100ų�ι��ʹ� ���� ��) : ";
	cin >> gas_europe;

	double gas_usa = (1 / gas_europe) * (62.14 * 3.875);
	
	cout << gas_europe << " L/100km = " << gas_usa << "mpg" << endl;
	return 0;
}
