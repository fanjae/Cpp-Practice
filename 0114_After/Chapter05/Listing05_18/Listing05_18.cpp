#include <iostream>
int main()
{
	using namespace std;
	char ch;

	int count = 0;
	cin.get(ch);					// 문자 하나를 읽는다.
	while (cin.fail() == false)		// EOF인지 검사한다.
	{
		cout << ch;					// 문자를 에코한다.
		++count;
		cin.get(ch);				// 다음 문자를 읽는다.
	}
	cout << count << " 문자를 읽었습니다.\n";
	return 0;
}

/*
Windows : Ctrl + Z키를 누르면 EOF를 입력할 수 있다.
Unix,Linux : Ctrl + D키를 누르면 EOF를 입력할 수 있다.
어떤 C++ 시스템은 키보드로 입력하는 시뮬레이션 EOF를 지원하지 않는다.
*/