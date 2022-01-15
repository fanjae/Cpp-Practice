#include <iostream>
int main()
{
	using namespace std;
	char ch;		// char 형 변수 선언

	cout << "원하는 문자 하나를 입력하시오 : " << endl;
	cin >> ch;
		
	cout << "감사합니다. ";
	cout << "당신이 입력한 문자는 " << ch << " 입니다." << endl;
	return 0;
}

/* cin은 키보드로부터 입력된 M을 값 77로 변환한다.
출력할 때 cout은 값 77을 문자 M으로 변환한다.

cin과 cout은 변수의 데이터형에 의해 안내를 받는다.
*/