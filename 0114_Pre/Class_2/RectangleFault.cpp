#include <iostream>
using namespace std;

class Point
{
	public: // 각 멤버변수가 public으로 되어 있어 어디서든 접근 가능 
		int x; // x좌표의 범위는 0이상 100이하 
		int y; // y좌표의 범위는 0이상 100이하 
};

class Rectangle
{
	public:
		Point upLeft;
		Point lowRight;
		
	public:
		void ShowRecInfo()
		{
			cout << "좌 상단 : " << '[' << upLeft.x << ", ";
			cout << upLeft.y << ']' << "\n";
			cout << "우 하단 : " << '[' << lowRight.x << ", ";
			cout << lowRight.y << ']' << "\n" << "\n";
		}
};

/* Rectangle 클래스에서 Point 객체를 사용하고 있다. 그러나,
Point가 유효한 범위 안에 있는지 전혀 확인 하지 않고 있음 */ 
int main(void)
{
	Point pos1 = {-2,4};
	Point pos2 = {5, 9};
	Rectangle rec ={pos2, pos1};
	rec.ShowRecInfo();
	return 0;
}
