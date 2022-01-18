#include <iostream>
int main(void)
{
	using namespace std;

	int donuts = 6;
	double cups = 4.5;

	cout << "donuts의 값 = " << donuts;
	cout << ", donuts의 주소 = " << &donuts << endl;
	// 참고 : unsigned (&donuts)와
	// unsigned (&cups)를 사용할 것을 요구하는 경우도 있다.

	cout << "cups의 값 = " << cups;
	cout << ", cups의 주소 = " << &cups << endl;
	return 0;
}

	// 포인터는 값 자체가 아니라 값의 주소를 저장하는 변수이다.
	// 주소 연산자(&)을 변수 앞에 붙이면 변수의 주소를 알아낼 수 있다.