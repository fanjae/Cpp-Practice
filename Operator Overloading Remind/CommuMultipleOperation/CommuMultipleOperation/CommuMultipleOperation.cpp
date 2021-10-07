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
	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, Point ref);
};
Point operator*(int times, Point ref)
{
	Point pos(ref.xpos * times, ref.ypos * times);
	return pos;
}


int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = pos * 3 * 2;
	cpy.ShowPosition();

	// 본 예제에서는 교환 법칙을 할 수 있도록 전역함수를 이용한 연산자 오버로딩을 추가하였다.

	cpy = 3 * pos;
	cpy.ShowPosition();
	return 0;

}