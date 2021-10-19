#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{
	}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	friend Point<int> operator+ (const Point<int>&, const Point<int> &);
	friend ostream& operator<< (ostream& os, const Point<int>& pos);
};

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2) // 함수 템플릿 처럼 보이나 + 연산자를오버로딩 하는 일반 함수이다.
{
	return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	// Point <int>는 템플릿 클래스의 자료형 선언에 사용된다. 
	// 즉, 템플릿 클래스인 Point<int>의 객체 둘을 인자로 받는 일반 함수이다.

}

ostream& operator<< (ostream& os, const Point<int>& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point <int> pos1(2, 4);
	Point <int> pos2(4, 8);
	Point <int> pos3 = pos1 + pos2;
	cout << pos1 << pos2 << pos3;
	return 0;
}