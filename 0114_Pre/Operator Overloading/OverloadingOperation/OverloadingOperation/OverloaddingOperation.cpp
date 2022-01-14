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
	Point operator +(const Point &ref) // 함수의 이름이 'operator+' 이다.
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos; // 두 객체의 멤버별 덧셈 결과로 새로운 Point 객체가 만들어지고 이것이 반환되어 pos3를 초기화 한다. (복사 생성자가 호출된다.)
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2; // Point pos3 = pos1.operator+(pos2); 와 동일한 문장이다.
	// operator 키워드 연산좌를 묶어서 함수의 이름을 정의하면,
	// 함수의 이름을 이용한 함수 호출뿐만 아니라, 연산자를 이용한 함수의 호출도 허용한다는 의미이다.
	// 만약, pos1형이 객체라면 pos1.operator+(pos2)라는 문장으로 바꿔 해석하겠다는 의미이다.


	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}