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
	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	const Point operator++(int) // 후위증가
	{
		const Point retobj(xpos, ypos); // const Point retobj(*this);
		// 값의 증가에 앞서 반환에 사용할 복사본을 만들어 놓고 있다.
		// 복사본은 값이 변경되면 안되어 const로 선언하였다.
		xpos += 1;
		ypos += 1;
		return retobj; // 멤버의 값이 증가하기 전에 만들어둔 복사본을 반환하고 있다. 이를 이용해 후위증가의 효과를 내고 있다. 
	}
	friend Point & operator--(Point &ref);
	friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point &ref, int) // 후위감소 
{
	const Point retobj(ref); // const 객체라 한다.
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
}

int main(void)
{
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;
	cpy.ShowPosition();
	pos.ShowPosition();

	return 0;
}