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
	const Point operator++(int)
	{
		const Point retobj(xpos, ypos);
		xpos+=1;
		ypos+=1;
		return retobj;
	}
	friend Point& operator--(Point &ref);
	friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point &ref, int) // 전역함수 형태의 후위감소 
{
	const Point retobj(ref);
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;
	// 반환형이 const로 되어있는데, 이는 반환 과정에서 새로운 객체가 생성되기 때문에
	// retobj의 const 선언 유무는 retobj 객체 반환에 어떠한 영향을 주지 않는다.

	// 즉, operator-- 함수로 인해 반환되는 임시 객체르 const 객체로 생성하겠다는 뜻이다.
	// 이때, const 객체를 대상으로는 const로 선언된 함수만 호출이 가능하다.
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