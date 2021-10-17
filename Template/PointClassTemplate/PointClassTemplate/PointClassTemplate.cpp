#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPoisition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main(void)
{
	Point <int> pos1(3, 4);
	pos1.ShowPoisition();

	Point <double> pos2(2.4, 3.6);
	pos2.ShowPoisition();

	Point <char> pos3('P', 'F'); // ��ǥ������ ���ڷ� ǥ���ϴ� ��Ȳ
	pos3.ShowPoisition();
	return 0;

	// Ŭ���� ���ø��� ������� ���ø� Ŭ������ ����.
	// 3���� ���ø� Ŭ������ �����ϸ�, Point<int>, Point<double>, Point<char> ���ø� Ŭ����

}