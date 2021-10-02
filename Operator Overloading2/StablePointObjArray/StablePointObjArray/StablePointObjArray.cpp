#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << "\n";
	return os;
}

class BoundCheckPointArray
{
private:
	Point *arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }

public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new Point[len];
		// Point ��ü�� �̷��� �迭�� ����.
		// ���ڸ� ���� �ʴ� void �������� ȣ���� ���� �迭 ��Ҹ� �̷�� ��ü�� �����ȴ�.
		// 10�࿡ ���ǵ� �����ڿ� ������ ����Ʈ ���� ���� ��ü�� ��� ����� 0���� �ʱ�ȭ
	}
	Point& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << "\n";
			exit(1);
		}
		return arr[idx];
	}
	Point operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << "\n";
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	BoundCheckPointArray()
	{
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4); // �ӽð�ü�� �����Ͽ� �迭��� �ʱ�ȭ (�ʱ�ȭ �������� ��� �� ��� ���� ����)
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
	{
		cout << arr[i];
	}
	return 0;
}