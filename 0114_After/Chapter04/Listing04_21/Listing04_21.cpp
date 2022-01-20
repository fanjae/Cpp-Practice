﻿#include <iostream>
struct inflatable		// 구조체 정의
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable *ps = new inflatable;		// 구조체를 위한 메모리 대입
	cout << "모형풍선의 이름을 입력하십시오 : ";
	cin.get(ps->name, 20);					// 멤버에 접근하는 제1 방법.
	cout << "부피를 세제곱 피트 단위로 입력하십시오 : ";
	cin >> (*ps).volume;					// 멤버에 접근하는 제2 방법.
	cout << "가격을 달러 단위로 입력하십시오: $";
	cin >> ps->price;

	cout << "이름 : " << (*ps).name << endl;				// 제2 방법
	cout << "부피 : " << ps->volume << " cubic feet\n";		// 제1 방법
	cout << "가격 : $" << ps->price << endl;				// 제1 방법
	delete ps;												// 구조체가 사용한 메모리 해제

	return 0;
}
