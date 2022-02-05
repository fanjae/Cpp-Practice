#include <iostream>
using namespace std;
int input(double arr[]);
void output(const int size, const double arr[]);
double avg_cal(const int size, const double arr[]);
int main(void)
{
	double golf_score[10];

	int arr_size = input(golf_score);
	output(arr_size, golf_score);
	double avg = avg_cal(arr_size, golf_score);
	cout << "평균 스코어 : " << avg << endl;
}
int input(double arr[])
{
	int size = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "번째 골프 스코어 입력(음수를 입력할 경우 입력 종료) : ";
		cin >> arr[i];
		if (arr[i] < 0)
		{
			size = i; // 음수 입력은 제외함.
			return size;
		}
		size = i + 1;
	}
	return size;
}
void output(const int size, const double arr[])
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "번째 골프 스코어 : " << arr[i] << endl;
	}
}
double avg_cal(const int size, const double arr[])
{
	double sum = 0;
	double avg = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	avg = sum / size;
	return avg;
}