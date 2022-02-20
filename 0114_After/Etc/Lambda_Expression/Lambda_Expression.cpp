#include <iostream>
#include <string>
using namespace std;

// 일반 함수 정의
void sum1(int a, int b)
{
	cout << "sum1 func : " << a + b << endl;
}

int main(void)
{
	// 일반 함수
	sum1(10, 20);

	// 람다 함수
	[](int a, int b)
	{
		cout << "sum2 lambda : " << a + b << endl;
	}(30, 40);

	// 람다의 기본 모양
	/* [] () {} ()
	[캡처] (매개변수) { 함수 동작 } (호출 인자 )
	매개변수 부분과 네 번째 부분은 생략이 가능하다.

	캡처는 람다 외부에 정의되어 있는 변수나 상수를 람다 내부에서 사용하기 위해서 사용된다.
	*/


	return 0;
}