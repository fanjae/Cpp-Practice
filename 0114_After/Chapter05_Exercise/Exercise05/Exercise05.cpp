#include <iostream>
#include <string>
using namespace std;

const int MONTH = 12;

int main()
{
	string month[MONTH] = { "1월","2월","3월","4월","5월","6월","7월","8월","9월","10월","11월","12월" };
	int selling[MONTH] = { 0 };
	int sum = 0;

	for (int i = 0; i < MONTH; i++)
	{
		cout << month[i] << " : ";
		cin >> selling[i];
		sum += selling[i];
	}
	
	cout << "총 판매량 : " << sum << endl;

}
	
