#include <iostream>
using namespace std;
int main()
{
	int value;
	int sum = 0;
	do
	{
		cout << "수를 입력하세요. (0 입력시 종료.)" << endl;
		cin >> value;
		sum += value;
	} while (value != 0);
	
	cout << "합계 : " << sum << endl;
	return 0;
}