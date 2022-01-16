#include <iostream>
int main(void)
{
	using namespace std;
	int yams[3];			// 3개의 원소를 가진 배열을 생성함.
	yams[0] = 7;			// 첫 번째 원소에 값을 대입한다.
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = { 200, 300, 50 };		// 배열을 생성하고 초기화함.

	cout << "고구마 합계 = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << yams[1] << "개가 들어 있는 포장은 ";
	cout << "개당 " << yamcosts[1] << "원씩입니다.\n";

	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];

	cout << "세 포장의 총 가격은 " << total << "원입니다.\n";
	cout << "\nyams 배열의 크기는 " << sizeof yams;
	cout << "바이트입니다.\n";
	cout << "원소 하나의 크기는 " << sizeof yams[0];
	cout << "바이트입니다.\n";
	return 0;
}
/* 컴파일러는 사용자가 적법한 인덱스를 사용하는지 검사하지 않는다.
예를들어, 존재하지 않는 yams[3]에 대입해도 컴파일러는 오류라고 판단하지 않는다.
하지만, 프로그램이 실행될 때 문제를 일으키므로, 적법한 인덱스를 사용해야 한다. */
