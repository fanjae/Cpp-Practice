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
		cout << '[ ' << xpos << ', ' << ypos << ']' << "\n";
	}
	friend ostream& operator<<(ostream&, const Point &);
};

// 멤버함수 형태로 하면 안되는 이유에 대해서 아래 내용을 참고하였다.
// https://pacs.tistory.com/entry/C-%EC%89%AC%ED%94%84%ED%8A%B8-%EC%97%B0%EC%82%B0%EC%9E%90-%EC%98%A4%EB%B2%84%EB%A1%9C%EB%94%A9-cout-cin-endl
ostream& operator<<(ostream& os, const Point& pos) // 전역함수 형태로 오버로딩 하면 문제되지 않는다.
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point pos1(1, 3);
	cout << pos1;

	Point pos2(101, 303);
	cout << pos2;
	return 0;
}
