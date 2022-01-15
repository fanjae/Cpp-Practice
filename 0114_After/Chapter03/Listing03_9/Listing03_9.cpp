#include <iostream>
int main()
{
	using namespace std;
	float a = 2.34E+22f;
	float b = a + 1.0f;

	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;
	return 0;
}

/* 부동 소수점형 상수는 기본적으로 double형으로 저장된다.
부동 소수점형 상수를 float형으로 저장하고 싶으면, f나 F를 접미어로,
long double형으로 저장하고 싶으면 l이나 L을 접미어로 사용해야 한다.
*/
