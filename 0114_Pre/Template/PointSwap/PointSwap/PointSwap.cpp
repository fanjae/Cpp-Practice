#include <iostream>
using namespace std;

template <typename T>
void SwapData(T& Data, T& Data2)
{
	T Data3;
	Data3 = Data;
	Data = Data2;
	Data2 = Data3;
}

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
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
};

int main(void)
{
	Point p1(3,5);
	Point p2(4,8);

	p1.ShowPosition();
	p2.ShowPosition();

	SwapData(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();

}