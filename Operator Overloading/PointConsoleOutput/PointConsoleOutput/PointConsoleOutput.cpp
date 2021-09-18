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

	cout << pos1; // �Ʒ� �� �������� ���� 19�࿡ ���ǵ� �Լ��� ȣ��ȴ�.
	cout << pos2; // << �������� ������ ������ ���� Point ��ü�̱� �����̴�.
	return 0;
	
}
