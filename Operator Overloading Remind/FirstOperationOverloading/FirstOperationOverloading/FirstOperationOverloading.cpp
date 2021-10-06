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
	Point operator+(const Point &ref) // 함수명 : operator+
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2); // opeartor+를 호출하면서 인자로 pos2 객체를 전달.
	// pos1 객체와 pos2 객체를 멤버별로 더함.
	// 여기서 새로운 객체가 만들어지고, 이를 토대로 pos3를 초기화한다.

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}