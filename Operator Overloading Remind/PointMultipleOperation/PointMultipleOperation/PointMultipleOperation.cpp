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
};



int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	cpy.ShowPosition();

	cpy = pos * 3 * 2;
	cpy.ShowPosition();

	// 곱하기(*) 연산자에 대한 오버로딩은 되어있다.
	// 하지만, 교환 법칙에 따라서 cpy = 3 * pos;와 같은 값으로 바꾸면 해석이 불가능하다.
	// 따라서 추가적인 조치가 필요하다.
	return 0;

}