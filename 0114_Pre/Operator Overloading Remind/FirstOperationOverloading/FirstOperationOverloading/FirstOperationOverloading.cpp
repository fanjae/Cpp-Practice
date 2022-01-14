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
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point operator+(const Point &ref) // �Լ��� : operator+
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2); // opeartor+�� ȣ���ϸ鼭 ���ڷ� pos2 ��ü�� ����.
	// pos1 ��ü�� pos2 ��ü�� ������� ����.
	// ���⼭ ���ο� ��ü�� ���������, �̸� ���� pos3�� �ʱ�ȭ�Ѵ�.

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}