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
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	Point operator-() // ��� �Լ� ������ �����ε�
	{
		Point pos(xpos * -1, ypos * -1);
		return pos;
	}
	friend Point& operator--(Point &ref);
	friend Point operator~(const Point &ref);
};

Point& operator--(Point &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

Point operator~(const Point &ref) // �����Լ� ������ �����ε�
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main(void)
{
	Point p1(1, 2);
	Point p2 = -p1;
	Point p3 = ~p1;

	p2.ShowPosition();
	p3.ShowPosition();

}