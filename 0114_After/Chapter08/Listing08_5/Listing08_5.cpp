#include <iostream>
double cube(double a);
double refcube(double &ra);
int main()
{
	using namespace std;
	double x = 3.0;

	cout << cube(x);
	cout << " = " << x << "의 세제곱\n";
	cout << refcube(x);
	cout << " = " << x << "의 세제곱\n";
	/* 함수에 전달하는 정보를 그 함수가 변경하지 않고 사용만 하도록 하려면,
	상수 참조를 사용해야 한다. */

	return 0;
}

double cube(double a) // 
{
	a *= a * a;
	return a;
}
double refcube(double &ra)
{
	ra *= ra * ra;
	return ra;
}
