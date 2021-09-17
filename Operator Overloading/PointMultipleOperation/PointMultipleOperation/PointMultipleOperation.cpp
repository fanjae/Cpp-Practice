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
	Point operator*(int times)
	{
		Point pos(xpos*times, ypos*times); // 곱셈 연산자를 오버로딩. (Point 객체와 정수 연산자간 곱셈 가능)
		return pos;
	}
};

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3; // pos.operator*(3) 이렇게 해석이 되기 위해서는 Point 객체가 곱셈 연산자 왼편에 와야 한다. 
	cpy.ShowPosition();

	cpy = pos * 3 * 2; 
	cpy.ShowPosition();
	return 0;
}