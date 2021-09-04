#include <iostream>
#include "Rectangle.h"
using namespace std;

// �̴ϼȶ������� �̿��� �������(��ü)�� �ʱ�ȭ �ϰ� �ִ�.
Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1,y1), lowRight(x2,y2)
{
	// ��� �̴ϼ� �������� ����, �������� ��ü �κ��� ��� ��찡 �����Ѵ�.
}

void Rectangle::ShowRecInfo() const
{
	cout << "�� ��� : " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << "\n";
	cout << "�� �ϴ� : " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << "\n";
}

