#include <iostream>

using namespace std;
struct Point // ��ǥ������ ��� ����ü 
{
	int xpos;
	int ypos;

	void MovePos(int x, int y) // ���� ��ǥ �̵� 
	{
		xpos = xpos + x;
		ypos = ypos + y;
	}
	
	void AddPoint(const Point &pos) // ���� ��ǥ ���� 
	{
		xpos = xpos + pos.xpos;
		ypos = ypos + pos.ypos;
	}

	void ShowPosition() // ���� x,y ��ǥ���� ��� 
	{
		cout << "[" << xpos << " ," << ypos << "]" << "\n"; 
	}
};
int main(void)
{
	Point pos1 = {12, 4};
	Point pos2 = {20, 30};
	
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();
	
	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;	
}
