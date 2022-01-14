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
		cout << "[" << xpos << ", " << ypos << "]" << "\n";
	}
	friend Point operator+(const Point &pos1, const Point &pos2); // friend ���� �Լ�(���� �����ڸ� �����ϰ� Ŭ���� ���� ����� ������ �� �ִ�.)
	
};

// �����Լ� ����Լ� ������� ���� �����ε� �� ���, ����Լ� ������� �����ε� �� �Լ���
// �����Լ� ������� �����ε� �� �Լ����� �켱�� ȣ��Ǿ�����.
// + �����ڰ� �����Լ��� ���·� �����ε� �Ǿ���.
// + ������ opeartor + (pos1, pos2)�� �ؼ��ȴ�.

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
