#include <iostream>

using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << "\n";
	}
	Point operator +=(const Point &ref) // ����Լ� ������ ������ �����ε�
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point operator -=(const Point &ref)  // ����Լ� ������ ������ �����ε�
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	friend Point operator+(const Point &pos1, const Point &pos2); // �����Լ� ������ ������ �����ε�
	friend Point operator-(const Point &pos1, const Point &pos2); // �����Լ� ������ ������ �����ε�
	friend bool operator==(const Point &pos1, const Point &pos2); // �����Լ� ������ ������ �����ε�
	friend bool operator!=(const Point &pos1, const Point &pos2); // �����Լ� ������ ������ �����ε�
};

Point operator+(const Point &pos1, const Point &pos2) // �����ε� �� + ������
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
Point operator-(const Point &pos1, const Point &pos2) // �����ε� �� - ������
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2) // �����ε� �� == ������
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Point &pos1, const Point &pos2) // �����ε� �� != ������
{
	return !(pos1 == pos2); // �����ε� �� == ������ ȣ��
}
int main(void)
{
	Point pos1(20, 30);
	Point pos2(5, 7);
	Point pos3(5, 7);

	(pos1 - pos2).ShowPosition(); // ��ȯ���� ��ü�̹Ƿ�, �Լ� ȣ���� �����ϴ�.
	(pos2 += pos3).ShowPosition(); // ��ȯ���� ������(��) �̹Ƿ� �Լ� ȣ���� �����ϴ�.

	if (pos2 == pos3)
	{
		cout << "equal" << "\n";
	}
	else
	{
		cout << "not equal" << "\n";
	}

	(pos2 -= pos3).ShowPosition();

	if (pos2 != pos3)
	{
		cout << "not equal" << "\n";
	}
	else
	{
		cout << "equal" << "\n";
	}
	return 0;
}