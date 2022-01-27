#include <iostream>
using namespace std;
int main(void)
{
	double data[10];
	double sum = 0;
	double avg = 0;
	int cnt = 0;
	int up_avg = 0;

	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "번째 기부금 : ";
		if (!(cin >> data[i]))
		{
			exit(EXIT_FAILURE);
		}
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
	{
		sum += data[i];
	}
	avg = sum / cnt;
	cout << "평균 : " << avg << endl;

	for (int i = 0; i < cnt; i++)
	{
		if (avg <= data[i])
		{
			up_avg++;
		}
	}
	cout << "평균보다 높은 기부금 : " << up_avg << "명 입니다." << endl;

}