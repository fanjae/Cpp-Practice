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

	Point <char> pos3('P', 'F'); // 좌표정보를 문자로 표시하는 상황
	pos3.ShowPoisition();
	return 0;

	// 클래스 템플릿을 기반으로 템플릿 클래스를 만들어냄.
	// 3개의 템플릿 클래스를 생성하며, Point<int>, Point<double>, Point<char> 템플릿 클래스

}