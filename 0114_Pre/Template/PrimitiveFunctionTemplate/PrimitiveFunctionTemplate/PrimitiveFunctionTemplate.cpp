#include <iostream>
using namespace std;

// 함수 템플릿
template <class T1, class T2> // 둘 이상의 템플릿 타입 명시, 키워드 typename 대신 class를 사용함.
void ShowData(double num) // 함수 템플릿의 매개변수도 기본 자료형으로 선언이 가능하다.
{
	cout << (T1)num << ", " << (T2)num << endl; // 
}
// 함수 템플릿

int main(void)
{
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}