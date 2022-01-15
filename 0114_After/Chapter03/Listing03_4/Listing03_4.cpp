#include <iostream>
using namespace std;
int main(void)
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "가슴둘레 " << chest << " (10진수) " << endl;
	cout << hex;		// 진법을 바꾸는 조정자
	cout << "허리둘레 " << waist << " (16진수)" << endl;
	cout << oct;		// 진법을 바꾸는 조정자
	cout << "인심길이 " << inseam << " (8진수)" << endl;
	return 0;
}

/*
cout << hex;와 같은 행위는 정수를 디스플레이하는 방식을 변경한다.
hex는 std 이름 공간의 일부이고, 이 프로그램이 std 이름 공간을 사용한다.
이 프로그램은 hex를 변수 이름으로 사용할 수 없다.
using 지시자를 생략하고, std::hex를 사용한다면, hex를 변수의 이름으로 사용할 수 있다.
*/
