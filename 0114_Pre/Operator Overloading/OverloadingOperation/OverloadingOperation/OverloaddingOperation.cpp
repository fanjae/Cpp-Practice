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
	Point operator +(const Point &ref) // �Լ��� �̸��� 'operator+' �̴�.
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos; // �� ��ü�� ����� ���� ����� ���ο� Point ��ü�� ��������� �̰��� ��ȯ�Ǿ� pos3�� �ʱ�ȭ �Ѵ�. (���� �����ڰ� ȣ��ȴ�.)
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2; // Point pos3 = pos1.operator+(pos2); �� ������ �����̴�.
	// operator Ű���� �����¸� ��� �Լ��� �̸��� �����ϸ�,
	// �Լ��� �̸��� �̿��� �Լ� ȣ��Ӹ� �ƴ϶�, �����ڸ� �̿��� �Լ��� ȣ�⵵ ����Ѵٴ� �ǹ��̴�.
	// ����, pos1���� ��ü��� pos1.operator+(pos2)��� �������� �ٲ� �ؼ��ϰڴٴ� �ǹ��̴�.


	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}