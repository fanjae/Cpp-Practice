#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;

	cout << "문자들을 입력하십시오; 끝내려면 #을 입력하십시오:\n";
	cin.get(ch);					// cin.get(ch) 함수를 사용한다.
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);				// cin.get(ch)를 다시 사용한다.
	}
	cout << endl << count << " 문자를 읽었습니다.\n";
	return 0;
}

// cin이 속해 있는 istreqam 클래스(iostream에 정의되어 있는)
// 이런 요구를 만족시키는 멤버 함수를 가지고 있음.
// cin.get(ch) 멤버 함수는 빈칸 문자까지도 입력받아 ch 변수에 저장.

