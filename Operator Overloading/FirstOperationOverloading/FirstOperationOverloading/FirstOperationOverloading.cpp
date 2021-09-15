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
	Point operator +(const Point &ref) // 함수의 이름이 'operator+' 이다.
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos); 
		return pos; // 두 객체의 멤버별 덧셈 결과로 새로운 Point 객체가 만들어지고 이것이 반환되어 pos3를 초기화 한다. (복사 생성자가 호출된다.)
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}