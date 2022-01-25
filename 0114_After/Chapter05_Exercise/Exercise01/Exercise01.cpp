#include <iostream>
using namespace std;
int main()
{
	int value, value2;
	int sum = 0;
	cout << "두 수를 입력하세요 : (작은 수 먼저 입력하세요)" << endl;
	cin >> value >> value2;

	for (int counter = value; counter <= value2; counter++)
	{
		sum += counter;
	}
	cout << "합계 : " << sum;
}
	