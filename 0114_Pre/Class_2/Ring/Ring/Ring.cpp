#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << "\n";
	}
};

class CirCle
{
private:
	Point Circle_Point;
	int radius;
public:
		void Init(const int x, const int y, const int temp_raidus)
		{
			Circle_Point.Init(x, y);
			radius = temp_raidus;
		}
		void ShowCircleInfo() const
		{
			cout << "radius : " << radius << "\n";
			Circle_Point.ShowPointInfo();
		}
};

class Ring
{
private:
	CirCle Inner;
	CirCle Outer;
public:
	void Init(const int inner_xpos, const int inner_ypos, const int inner_radius, const int outer_xpos, const int outer_ypos, const int outer_radius)
	{
		Inner.Init(inner_xpos, inner_ypos, inner_radius);
		Outer.Init(outer_xpos, outer_ypos, outer_radius);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << "\n";
		Inner.ShowCircleInfo(); // Ring 클래스가 ShowRingInfo()에서 ShowCircleInfo()를 호출하는 점과, 다시 ShowCircleInfo()에서 ShowPointInfo()를 호출 할 때,
		// 각 클래스가 자신의 정보를 출력하기 위한 함수를 멤버에 포함 시켜 캡슐화를 완성함.
		cout << "Outter Circle Info... " << "\n";
		Outer.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}