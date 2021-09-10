#include <iostream>
using namespace std;

class Base
{
public:
	void BaseFunc()
	{
		cout << "Base Function" << "\n";
	}
};

class Derived : public Base
{
public:
	void DerivedFunc()
	{
		cout << "Derived Function" << "\n";
	}
};

int main(void)
{
	Base *bptr = new Derived(); // 컴파일 문제 없음.
	// bptr->DerivedFunc()		// 컴파일 에러

	/* bptr이 Base형 포인터이기 때문에 불가능하다.
	C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단한다.
	실제로 가리키는 객체의 자료형을 기준으로 판단하지 않는다. */

	// Derived *dptr = btpr;	// 같은 이유로 이 문장도 컴파일 에러가 발생한다.
	// 컴파일러는 앞서 bptr이 실제로 가리키는 객체가 Derived 객체라는 사실을 기억하지 않는다.

	// 이에 반면 아래와 같은 경우는 컴파일러가 문제를 삼지 않는다.
	Derived *dptr = new Derived();
	Base *bptr2 = dptr;

	// dptr은 Derived 클래스의 포인터 변수이다. 이 포인터가 가리키는 객체는 분명 Base 클래스를 직접 혹은 간접적으로 상속한다.
	// 따라서 참조가 가능하다.



}
