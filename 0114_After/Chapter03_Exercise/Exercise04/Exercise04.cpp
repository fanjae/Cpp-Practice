#include <iostream>
using namespace std;
int main(void)
{
	long input_sec;
	const int TIME_DAY = 86400;
	const int TIME_HOUR = 3600;
	const int TIME_MIN = 60;
	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> input_sec;

	int day = input_sec / TIME_DAY;
	int hour = (input_sec - day * TIME_DAY) / (TIME_HOUR);
	int min = (input_sec - day * TIME_DAY - hour * TIME_HOUR) / TIME_MIN;
	int second = input_sec % TIME_MIN;

	cout << input_sec << "�� = " << day << "��, " << hour << "�ð�, " << min << "��, " << second << "��";
}
