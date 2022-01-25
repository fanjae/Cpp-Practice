#include <iostream>
const int First_a_value = 100000;

using namespace std;
int main(void)
{
	int year = 1;
	int A = 100000;
	int B = 100000;

	while (A >= B)
	{
		A += 0.10 * First_a_value;
		B += 0.05 * B;

		cout << year << "년 후의 투자 가치" << endl;
		cout << "A : " << A << "원" << endl;
		cout << "B : " << B << "원" << endl;
		year++;
	}

}
