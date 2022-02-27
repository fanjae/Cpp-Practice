#include <iostream>
extern int tom;					// tom은 다른 파일에 정의
static int dick = 10;			// 외부 dick의 앞을 가림.
int harry = 200;				// 외부 변수 정의
								// twofile1.cpp의 harry와 충돌하지 않음.
void remote_access()
{
	using namespace std;
	cout << "remote_access()가 보고하는 세 변수의 주소 : \n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
}