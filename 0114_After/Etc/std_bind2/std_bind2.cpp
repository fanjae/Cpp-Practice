#include <iostream>
#include <string>
#include <functional>

using namespace std;
/* bind란?
함수의 일부 매개 변수를 고정 값으로 세팅한 후, 한번 Wrapping 하여 사용할 수 있게 해주는 함수입니다. */

/* bind를 할당하는 변수의 자료형을 따라 2가지 형태 존재.
1. function class 사용
std::function <warpping할 함수의 형태> 변수명 = bind(함수명, 인자1, 인자2...~);
함수명을 변수에 연결시킴.
2. auto 키워드 사용
auto 변수명 = bind(함수명, 인자1, 인자2)
함수명을 변수에 연결시킴

Ref : https://doitnow-man.tistory.com/205
*/
int test(string name, int a, int b)
{
	cout << name << " " << a * b << endl;
	return a * b;
}
int main()
{
	function<int()> f = bind(test, "hello", 1, 2);
	auto g = bind(test, "hello", 1, 2);
	f();
	g();
}