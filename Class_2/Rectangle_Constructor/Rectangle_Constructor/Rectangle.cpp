#include <iostream>
#include "Rectangle.h"
using namespace std;

// 이니셜라이저를 이용한 멤버변수(객체)를 초기화 하고 있다.
Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1,y1), lowRight(x2,y2)
{
	// 멤버 이니셜 라이저를 사용시, 생성자의 몸체 부분이 비는 경우가 존재한다.
}

void Rectangle::ShowRecInfo() const
{
	cout << "좌 상단 : " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << "\n";
	cout << "우 하단 : " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << "\n";
}

