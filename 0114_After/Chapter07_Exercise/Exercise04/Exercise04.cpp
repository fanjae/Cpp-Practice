#include <iostream>
// 어떤 C++에서는 long double 대신에 double형을 사용해야함.
long double probability(unsigned numbers, unsigned pikcs);
using namespace std;
int main()
{
	const double first_total = 47;
	const double first_choices = 5;

	const double second_total = 27;
	const double second_choices = 1;

	cout << probability(first_total, first_choices) * probability(second_total, second_choices) << endl;
	// 47개의 수 중 5개 의 수를 바르게 뽑을 확률 * 27개의 수 중 1개의 수를 바르게 뽑을 확률
	return 0;
}

// 이 함수는 numbers개의 수 중에서
// picks개의 수를 정확하게 뽑을 확률을 계산한다.
long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;				// 이 자리에는 지역 변수들이 온다.
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
	{
		result = result * n / p;
	}
	return result;
}

