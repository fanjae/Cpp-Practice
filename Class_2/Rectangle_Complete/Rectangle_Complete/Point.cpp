#include <iostream>
#include "Point.h"
using namespace std;

bool Point::InitMembers(int xpos, int ypos)
{
	if (xpos < 0 || ypos < 0)
	{
		cout << "벗어난 범위의 값 전달" << "\n";
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

/* 멤버변수에 값을 저장하는 함수가 유효하지 않은 범위의 값을
전달하면, 에러 메시지를 출력하고 값 저장을 허용하지 않토록 정의됨.

이를 통해 잘못된 값을 저장하지 않고, 잘못된 값의 저장을 시도한 경우
문제를 확인할 수 있다. */

/* 멤버 변수를 private로 선언하고, 해당 변수에 접근하는 함수 별도로 정의하여
안전한 형태로 멤버변수의 접근을 유도하는 것이 정보은닉이다. */

/* Access Function : 아래 4개의 함수를 Access Function 이라고 하는데,
멤버변수를 private으로 선언하여 클래스 외부에서 멤버변수 접근을 목적으로 정의되는 함수이다. */

/* const 함수 내에서는 멤버 변수에 저장된 값을 변경하지 않는다.
const 함수 내에서는 const가 아닌 함수의 호출이 제한된다. */

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

bool Point::SetX(int xpos)
{
	if (xpos < 0 || xpos > 100)
	{
		cout << "벗어난 범위의 값 전달" << "\n";
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (ypos < 0 || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << "\n";
		return false;
	}
	y = ypos;
	return true;
}