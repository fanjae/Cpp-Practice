#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	void Print() const {
		cout << x << ',' << y << endl;
	}
};

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	Print(pt);	// cout << pt; 연산이 불가능하여 불가능.
	// 템플릿 특수화가 필요한 이유.

	return 0;
}
