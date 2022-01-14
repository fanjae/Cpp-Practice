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
	friend Point operator+(const Point &pos1, const Point &pos2); // private 멤버에 접근 가능하도록 Friend 선언
};

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2; // +연산자가 전역함수의 형태로 오버로딩되어 + 연산은 operator+(pos1,pos2)
	// 멤버함수로 오버로딩된 경우에는 pos1.operator+(pos2);로 해석된다.

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}