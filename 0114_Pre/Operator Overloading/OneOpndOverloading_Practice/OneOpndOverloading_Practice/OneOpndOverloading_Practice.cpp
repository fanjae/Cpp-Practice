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
	Point& operator++() // ++ 연산자 멤버함수의 형태로 오버로딩
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	Point operator-() // - 부호 연산자 멤버함수 형태로 오버로딩
	{
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point& operator--(Point &ref);
	friend Point operator~ (const Point &);
};

Point& operator--(Point &ref) // -- 연산자가 전역함수 형태로 오버로딩
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

Point operator~(const Point &ref) // ~ 연산자 전역함수 형태로 오버로딩
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}
int main(void)
{
	Point pos1(9, -7);
	pos1.ShowPosition();
	
	Point pos2 = -pos1;
	pos2.ShowPosition();
	(~pos2).ShowPosition();
	pos2.ShowPosition();
	return 0;
}