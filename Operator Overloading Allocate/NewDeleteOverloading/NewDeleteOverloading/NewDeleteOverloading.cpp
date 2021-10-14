#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);

	void *operator new (size_t size)
	{
		cout << "operator new : " << size << endl;
		void *adr = new char[size]; // 바이트 단위로 필요한 메모리 공간을 할당함.
		// 할당에 사용되는 크기 정보는 컴파일러가 계산함.
		// char 형을 대상으로 new 연산을 하는 문장은 malloc 함수의 호출문으로 대신할 수 있다.

		return adr;
	}
	void operator delete (void *adr)
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
		// char 형으로 할당된 메모리 공간을 해제하는 것이기 때문에,
		// free 함수의 호출문으로 대신할 수 있고, 실제로 free 함수를 대신 호출한다.
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point * ptr = new Point(3, 4);
	// 객체가 생성되지 않았음에도 불구하고, 멤버함수가 호출된 이유는.
	// operator new함수와 operator delete 함수가 static 함수이기 때문이다.
	cout << *ptr;
	delete ptr;
	return 0;
}

