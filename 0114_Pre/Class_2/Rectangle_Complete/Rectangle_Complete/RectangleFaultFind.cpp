#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
	Point pos1;
	if (!pos1.InitMembers(-2, 4))
	{
		cout << "�ʱ�ȭ ����" << "\n";
	}
	if (!pos1.InitMembers(2, 4))
	{
		cout << "�ʱ�ȭ ����" << "\n";
	}

	Point pos2;
	if (!pos2.InitMembers(5, 9))
	{
		cout << "�ʱ�ȭ ����" << "\n";
	}

	Rectangle rec;
	if (!rec.InitMembers(pos2, pos1))
	{
		cout << "���簢�� �ʱ�ȭ ����" << "\n";
	}

	if (!rec.InitMembers(pos1, pos2))
	{
		cout << "���簢�� �ʱ�ȭ ����" << "\n";
	}

	rec.ShowRecInfo();
	return 0;
}