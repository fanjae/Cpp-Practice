#include <iostream>
using namespace std;
int main(void)
{
	long input_sec;
	const int TIME_DAY = 86400;
	const int TIME_HOUR = 3600;
	const int TIME_MIN = 60;
	cout << "초 수를 입력하시오: ";
	cin >> input_sec;

	int day = input_sec / TIME_DAY;
	int hour = (input_sec - day * TIME_DAY) / (TIME_HOUR);
	int min = (input_sec - day * TIME_DAY - hour * TIME_HOUR) / TIME_MIN;
	int second = input_sec % TIME_MIN;

	cout << input_sec << "초 = " << day << "일, " << hour << "시간, " << min << "분, " << second << "초";
}
