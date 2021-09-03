#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
	{
		cout << "�߸��� ��ġ���� ����" << "\n";
		return false;
	}
	upLeft = ul;
	lowRight = lr;
	return true;
}

void Rectangle::ShowRecInfo() const
{
	cout << "�� ��� : " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << "\n";
	cout << "�� �ϴ� : " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << "\n" << "\n";
}