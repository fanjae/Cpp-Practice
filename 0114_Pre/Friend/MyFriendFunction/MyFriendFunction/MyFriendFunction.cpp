#include <iostream>
using namespace std;

class Point; // Point가 클래스 이름임을 명시

class PointOP
{
private:
	int opcnt;
public:
	PointOP() : opcnt(0)
	{

	}
	Point PointAdd(const Point &, const Point &);
	Point PointSub(const Point &, const Point &);

	~PointOP()
	{
		cout << "Operation times : " << opcnt << "\n";
	}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{

	}
	friend Point PointOP::PointAdd(const Point &, const Point &); // PointOP 클래스의 멤버함수를 Friend 선언
	friend Point PointOP::PointSub(const Point &, const Point &); // PointOP 클래스의 멤버함수를 Friend 선언
	friend void ShowPointPos(const Point &);
};

Point PointOP::PointAdd(const Point &pnt1, const Point &pnt2) // Friend로 선언되어 있기 때문에, Private 멤버에 접근 가능하다.
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point &pnt1, const Point &pnt2) // Friend로 선언되어 있기 때문에, Private 멤버에 접근 가능하다.
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
	return 0;
}

void ShowPointPos(const Point& pos) // Friend 선언되어 있기 때문에 private 멤버에 바로 접근할 수 있다.
{
	cout << "x : " << pos.x << ", ";
	cout << "y : " << pos.y << "\n";
}