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
	Point& operator++() // ++ 연산자 멤버함수의 형태로 오버로딩
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref) // -- 연산자가 전역함수 형태로 오버로딩
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main(void)
{
	Point pos(1, 2); 
	++pos; // pos.operator++();로 해석된다.
	pos.ShowPosition();
	--pos; // operator--(pos);로 해석된다.
	pos.ShowPosition();

	++(++pos);
	// ++(pos.operator++());
	// ++(pos의 참조 값);
	// (pos의 참조 값).operator++();

	pos.ShowPosition();
	--(--pos);
	// --(--pos);
	// --(operator--(pos));
	// --(pos의 참조갓);
	// operator--(pos의 참조값);

	pos.ShowPosition();
	return 0;
}