#include <iostream>
using namespace std;
int main()
{
	int tvarp;
	double tax = 0;
	cout << "트바프를 입력하시오 : ";
	cin >> tvarp;

	if (tvarp >= 35000)
	{
		tax += (tvarp - 35000) * 0.20;
		tax += 20000 * 0.15;
		tax += 10000 * 0.10;
		tax += 5000 * 0;
	}
	else if (tvarp >= 20000)
	{
		tax += (tvarp - 20000) * 0.20;
		tax += 10000 * 0.10;
		tax += 5000 * 0;
	}
	else if (tvarp >= 10000)
	{
		tax += (tvarp - 10000) * 0.10;
		tax += 5000 * 0;
	}
	else
	{
		tax += (tvarp - 5000) * 0;
	}


	cout << "납부할 세금은 " << tax << " 트바프 입니다.";
}