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
		cout << '[' << xpos << ", " << ypos << ']' << "\n";
	}
	friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator << (ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << "\n";
	return os;
}

int main(void)
{
	Point pos1(1, 3);
	Point pos2(101, 303);

	cout << pos1; // 아래 두 문장으로 인해 19행에 정의된 함수가 호출된다.
	cout << pos2; // << 연산자의 오른편에 등장한 것이 Point 객체이기 때문이다.
	return 0;
	
}
