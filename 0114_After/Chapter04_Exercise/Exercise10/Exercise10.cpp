#include <iostream>
#include <array>
using namespace std;
int main(void)
{
	array<double, 3> running;

	cout << "첫번째 달리기 기록 : ";
	cin >> running[0];

	cout << "두번째 달리기 기록 : ";
	cin >> running[1];

	cout << "세번째 달리기 기록 : ";
	cin >> running[2];

	cout << "달리기 기록 평균 : " << (running[0] + running[1] + running[2]) / 3 << endl;

}