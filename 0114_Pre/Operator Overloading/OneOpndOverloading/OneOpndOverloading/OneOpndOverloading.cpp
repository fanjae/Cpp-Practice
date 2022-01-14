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
	Point& operator++() // ++ ������ ����Լ��� ���·� �����ε�
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref) // -- �����ڰ� �����Լ� ���·� �����ε�
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main(void)
{
	Point pos(1, 2); 
	++pos; // pos.operator++();�� �ؼ��ȴ�.
	pos.ShowPosition();
	--pos; // operator--(pos);�� �ؼ��ȴ�.
	pos.ShowPosition();

	++(++pos);
	// ++(pos.operator++());
	// ++(pos�� ���� ��);
	// (pos�� ���� ��).operator++();

	pos.ShowPosition();
	--(--pos);
	// --(--pos);
	// --(operator--(pos));
	// --(pos�� ������);
	// operator--(pos�� ������);

	pos.ShowPosition();
	return 0;
}