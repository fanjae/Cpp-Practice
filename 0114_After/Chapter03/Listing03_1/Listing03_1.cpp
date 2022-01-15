// 정수 한계값
#include <iostream>
#include <climits> // 구식 C++에서는 limits.h를 사용한다.
int main()
{
	using namespace std;
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	// sizeof 연산자는 데이터형이나 변수의 크기를 알아낸다.
	cout << "int는 " << sizeof(n_int) << " 바이트이다." << endl;
	cout << "short는 " << sizeof(n_short) << " 바이트이다." << endl;
	cout << "long은 " << sizeof(n_long) << " 바이트이다." << endl;
	cout << "long long은 " << sizeof(n_llong) << " 바이트이다." << endl;
	cout << endl;

	cout << "최대값:" << endl;
	cout << "int : " << n_int << endl;
	cout << "short : " << n_short << endl;
	cout << "long : " << n_long << endl;
	cout << "long long : " << n_llong << endl << endl;
	cout << "int의 최소값 = " << INT_MIN << endl;
	cout << "바이트 당 비트 수 = " << CHAR_BIT << endl;
	return 0;
}