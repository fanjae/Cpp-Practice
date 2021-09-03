#include <iostream>
#include "Point.h"
using namespace std;

bool Point::InitMembers(int xpos, int ypos)
{
	if (xpos < 0 || ypos < 0)
	{
		cout << "��� ������ �� ����" << "\n";
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

/* ��������� ���� �����ϴ� �Լ��� ��ȿ���� ���� ������ ����
�����ϸ�, ���� �޽����� ����ϰ� �� ������ ������� ����� ���ǵ�.

�̸� ���� �߸��� ���� �������� �ʰ�, �߸��� ���� ������ �õ��� ���
������ Ȯ���� �� �ִ�. */

/* ��� ������ private�� �����ϰ�, �ش� ������ �����ϴ� �Լ� ������ �����Ͽ�
������ ���·� ��������� ������ �����ϴ� ���� ���������̴�. */

/* Access Function : �Ʒ� 4���� �Լ��� Access Function �̶�� �ϴµ�,
��������� private���� �����Ͽ� Ŭ���� �ܺο��� ������� ������ �������� ���ǵǴ� �Լ��̴�. */

/* const �Լ� �������� ��� ������ ����� ���� �������� �ʴ´�.
const �Լ� �������� const�� �ƴ� �Լ��� ȣ���� ���ѵȴ�. */

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

bool Point::SetX(int xpos)
{
	if (xpos < 0 || xpos > 100)
	{
		cout << "��� ������ �� ����" << "\n";
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (ypos < 0 || ypos > 100)
	{
		cout << "��� ������ �� ����" << "\n";
		return false;
	}
	y = ypos;
	return true;
}