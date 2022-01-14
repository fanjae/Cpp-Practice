#include <iostream>

using namespace std;
struct Point // 좌표정보를 담는 구조체 
{
	int xpos;
	int ypos;

	void MovePos(int x, int y) // 점의 좌표 이동 
	{
		xpos = xpos + x;
		ypos = ypos + y;
	}
	
	void AddPoint(const Point &pos) // 점의 좌표 증가 
	{
		xpos = xpos + pos.xpos;
		ypos = ypos + pos.ypos;
	}

	void ShowPosition() // 현재 x,y 좌표정보 출력 
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

