#include <iostream>
const int Max = 5;
int main()
{
	using namespace std;
	// 데이터를 입력받는다.

	int golf[Max];
	cout << "골프 점수를 입력하십시오. \n";
	cout << "총 " << Max << " 라운드 점수를 입력해야 합니다.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();			// 입력을 초기화한다.
			while (cin.get() != '\n')
			{
				continue;			// 불량 입력을 제거한다.
			}
			cout << "골프 점수를 입력하십시오: ";
		}
	}
// 평균을 계산한다.
	double total = 0.0;
	for (i = 0; i < Max; i++)
	{
		total += golf[i];
	}
// 결과를 보고한다.
	cout << "총 " << Max << "라운드의 평균 점수 = "
		 << total / Max << endl;

	return 0;
}

/* 사용자가 88을 입력하면, cin 표현식은 true가 됨.
cin이 true이므로, !(cin>> golf[i])는 false가 되어 while 루프가 종료됨.
그러나 must i? 를 입력한 경우, cin 표현식은 false가 되고, !(cin >> golf[i])는 true가 되어.
while 루프를 진행한다. */