#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y)
	{
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
	CirCle(const int x, const int y, const int temp_radius) : Circle_Point(x, y), radius(temp_radius)
	{
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
	Ring(const int inner_xpos, const int inner_ypos, const int inner_radius, const int outer_xpos, const int outer_ypos, const int outer_radius) : Inner(inner_xpos, inner_ypos, inner_radius), Outer(outer_xpos, outer_ypos, outer_radius)
	{
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << "\n";
		Inner.ShowCircleInfo(); // Ring Ŭ������ ShowRingInfo()���� ShowCircleInfo()�� ȣ���ϴ� ����, �ٽ� ShowCircleInfo()���� ShowPointInfo()�� ȣ�� �� ��,
		// �� Ŭ������ �ڽ��� ������ ����ϱ� ���� �Լ��� ����� ���� ���� ĸ��ȭ�� �ϼ���.
		cout << "Outter Circle Info... " << "\n";
		Outer.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring(1,1,4,2,2,9);
	ring.ShowRingInfo();
	return 0;
}