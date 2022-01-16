#include <iostream>
int main()
{
	using namespace std;
	int auks, bats, coots;

	// 다음 구문은 두 값을 double형으로 더한 후 그 합을 int형으로 변환하여 대입힌다.
	auks = 19.99 + 11.99;

	// 다음 두 구문은 두 값을 int형으로 변환한 후에 더한다.
	bats = (int) 19.99 + (int) 11.99; // C Style
	coots = int(19.99) + int(11.99);  // C++ Style

	cout << "바다오리 = " << auks << ", 박쥐 = " << bats;
	cout << ", 검둥오리 = " << coots << endl;

	char ch = 'Z';
	cout << "코드 " << ch << " 의 값은 ";				// char형으로 출력
	cout << int(ch) << endl;							// int형으로 출력
	cout << "네, 코드 Z의 값은 ";
	cout << static_cast<int>(ch) << endl;				// int형으로 출력

	/* static_cast<> 연산자는 어떤 수치 데이터형을 다른 수치 데이터형으로 변환하는데 사용한다.
	value를 typeName형으로 변환한다.
	*/
	return 0;
}