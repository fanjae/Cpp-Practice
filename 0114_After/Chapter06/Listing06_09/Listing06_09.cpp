﻿#include <iostream>
int main()
{
	using namespace std;
	int a, b;
	cout << "두 개의 정수를 입력하십시오 : ";
	cin >> a >> b;
	cout << "둘 중에서 더 큰 정수는 ";
	int c = a > b ? a : b; // a > b 이면 c = a, 그렇지 않으면 c = b
	cout << c << "입니다.\n";
	return 0;
}
//  expression1 ? expression2 : expression3
// expression1이 true이면 expression2의 값이 전체 조건 표현식의 값이 됨.
// false이면 expression3의 값이 전체 조건 표현식의 값이 됨.