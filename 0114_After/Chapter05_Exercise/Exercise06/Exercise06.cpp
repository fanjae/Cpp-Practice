#include <iostream>
#include <string>
using namespace std;

const int YEARS = 3;
const int MONTH = 12;

int main()
{
	string month[MONTH] = { "1월","2월","3월","4월","5월","6월","7월","8월","9월","10월","11월","12월" };
	int selling[YEARS][MONTH] = { 0 };
	int sum[YEARS] = { 0 };
	int all_years_sum = 0;

	for (int i = 0; i < YEARS; i++)
	{
		cout << i + 1 << "년째 판매량" << endl;
		for (int j = 0; j < MONTH; j++)
		{
			cout << month[j] << " : ";
			cin >> selling[i][j];
			sum[i] += selling[i][j];
		}
		all_years_sum += sum[i];
		cout << "연간 판매량 : " << sum[i] << endl;
	}
	cout << "총 판매량 : " << all_years_sum << endl;

}

