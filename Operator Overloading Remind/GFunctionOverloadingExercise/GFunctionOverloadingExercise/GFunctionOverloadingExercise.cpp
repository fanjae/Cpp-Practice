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
	Point& operator+=(const Point &ref) // += 연산자 오버로딩
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point &ref)// -= 연산자 오버로딩
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	friend Point operator+(const Point &pos1, const Point &pos2); // friend 전역 함수(접근 지정자를 무시하고 클래스 내부 멤버에 접근할 수 있다.)
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);

};

// 전역함수 멤버함수 기반으로 동시 오버로딩 할 경우, 멤버함수 기반으로 오버로딩 된 함수가
// 전역함수 기반으로 오버로딩 된 함수보다 우선시 호출되어진다.
// + 연산자가 전역함수의 형태로 오버로딩 되었다.
// + 연산은 opeartor + (pos1, pos2)로 해석된다.

Point operator+(const Point &pos1, const Point &pos2) 
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.xpos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2) // == 연산자 오버로딩
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
bool operator!=(const Point &pos1, const Point &pos2) // != 연산자 오버로딩
{
	if ((pos1 == pos2) == true)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	pos1 += pos2;
	pos1.ShowPosition();

	if (pos1 == pos3)
	{
		cout << "is Same" << endl;
	}
	
	if (pos1 != pos2)
	{
		cout << "is not Same" << endl;
	}

	return 0;
}

