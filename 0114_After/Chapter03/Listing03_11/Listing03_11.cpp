#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "정수 나눗셈 : 9/5 = " << 9 / 5 << endl;
	cout << "부동 소수점수 나눗셈: 9.0 / 5.0 = ";
	cout << 9.0 / 5.0 << endl;
	cout << "혼합 나눗셈: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "double형 상수 : 1e7/9.0 = ";
	cout << 1.e7 / 9.0 << endl;
	cout << "float형 상수 : 1e7f/9.0f = ";
	cout << 1.e7f / 9.0f << endl;
	return 0;
}

/* 여러 가지 데이터형을 혼합하면, 모든 데이터형들이 동일한 데이터형으로 변환된다.
부동 소수점형 상수는 기본적으로 double형을 사용한다. */