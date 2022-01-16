#include <iostream>
using namespace std;
int main(void)
{
	double gas_europe;
	cout << "휘발유 소비량을 작성하세요(100킬로미터당 리터 수) : ";
	cin >> gas_europe;

	double gas_usa = (1 / gas_europe) * (62.14 * 3.875);
	
	cout << gas_europe << " L/100km = " << gas_usa << "mpg" << endl;
	return 0;
}
