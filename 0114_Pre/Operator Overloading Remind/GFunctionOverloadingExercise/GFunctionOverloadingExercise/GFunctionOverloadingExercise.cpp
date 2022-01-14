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
	Point& operator+=(const Point &ref) // += ������ �����ε�
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point &ref)// -= ������ �����ε�
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	friend Point operator+(const Point &pos1, const Point &pos2); // friend ���� �Լ�(���� �����ڸ� �����ϰ� Ŭ���� ���� ����� ������ �� �ִ�.)
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);

};

// �����Լ� ����Լ� ������� ���� �����ε� �� ���, ����Լ� ������� �����ε� �� �Լ���
// �����Լ� ������� �����ε� �� �Լ����� �켱�� ȣ��Ǿ�����.
// + �����ڰ� �����Լ��� ���·� �����ε� �Ǿ���.
// + ������ opeartor + (pos1, pos2)�� �ؼ��ȴ�.

Point operator+(const Point &pos1, const Point &pos2) 
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.xpos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2) // == ������ �����ε�
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
bool operator!=(const Point &pos1, const Point &pos2) // != ������ �����ε�
{
	if ((pos1 == pos2) == true)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	pos1 += pos2;
	pos1.ShowPosition();

	if (pos1 == pos3)
	{
		cout << "is Same" << endl;
	}
	
	if (pos1 != pos2)
	{
		cout << "is not Same" << endl;
	}

	return 0;
}

