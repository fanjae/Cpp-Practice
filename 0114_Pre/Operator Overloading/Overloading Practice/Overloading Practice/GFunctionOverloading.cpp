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
	Point operator +=(const Point &ref) // 멤버함수 형태의 연산자 오버로딩
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point operator -=(const Point &ref)  // 멤버함수 형태의 연산자 오버로딩
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	friend Point operator+(const Point &pos1, const Point &pos2); // 전역함수 형태의 연산자 오버로딩
	friend Point operator-(const Point &pos1, const Point &pos2); // 전역함수 형태의 연산자 오버로딩
	friend bool operator==(const Point &pos1, const Point &pos2); // 전역함수 형태의 연산자 오버로딩
	friend bool operator!=(const Point &pos1, const Point &pos2); // 전역함수 형태의 연산자 오버로딩
};

Point operator+(const Point &pos1, const Point &pos2) // 오버로딩 된 + 연산자
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}
Point operator-(const Point &pos1, const Point &pos2) // 오버로딩 된 - 연산자
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2) // 오버로딩 된 == 연산자
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Point &pos1, const Point &pos2) // 오버로딩 된 != 연산자
{
	return !(pos1 == pos2); // 오버로딩 된 == 연산자 호출
}
int main(void)
{
	Point pos1(20, 30);
	Point pos2(5, 7);
	Point pos3(5, 7);

	(pos1 - pos2).ShowPosition(); // 반환형이 객체이므로, 함수 호출이 가능하다.
	(pos2 += pos3).ShowPosition(); // 반환형이 참조자(형) 이므로 함수 호출이 가능하다.

	if (pos2 == pos3)
	{
		cout << "equal" << "\n";
	}
	else
	{
		cout << "not equal" << "\n";
	}

	(pos2 -= pos3).ShowPosition();

	if (pos2 != pos3)
	{
		cout << "not equal" << "\n";
	}
	else
	{
		cout << "equal" << "\n";
	}
	return 0;
}