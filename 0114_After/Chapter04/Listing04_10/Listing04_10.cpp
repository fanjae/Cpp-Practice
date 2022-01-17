#include <iostream>
#include <string>				// string 클래스를 사용하기 위해
#include <cstring>				// C 스타일 문자열 라이브러리
int main()
{
	using namespace std;
	char charr[20];
	string str;

	cout << "입력 이전에 charr에 있는 문자열의 길이 : " << strlen(charr) << endl;
	cout << "입력 이전에 str에 있는 문자열의 길이 : " << str.size() << endl;
	cout << "텍스트 한 행을 입력하세요 : \n";
	cin.getline(charr, 20);					// 최대 길이를 나타낸다.

	// 1. 초기화 되지 않은 배열의 내용은 정의되지 않는다.
	// strlen() 함수는 배열의 첫번째 원소에 출발해서 널 문자에 도달할때 까지의 바이트들을 카운트 한다.
	// 초기화 되지 않은 string 객체는 자동으로 크기가 0으로 설정된다.
	// cin.getline(charr,20); : getline() 함수가 istream 클래스를 위한 클래스 메서드 라는 것을 나타냄.



	cout << "입력한 텍스트 : " << charr << endl;
	cout << "또 다른 텍스트 한 행을 입력하시오 : \n";
	getline(cin, str); // 이제 cin은 길이 지정자가 아니라 매개변수
	// getline()이 클래스 메서드가 아니다. 따라서, 입력을 어디에서 찾을 것인지를 나타내는 매개변수로 cin을 사용한다.

	cout << "입력한 텍스트 : " << str << endl;
	cout << "입력 이후에 charr에 있는 문자열의 길이 : " << strlen(charr) << endl;
	cout << "입력 이후에 str에 있는 문자열의 길이 : " << str.size() << endl;

	/* istream 클래스 메서드들은 있다. 하지만, string 객체를 처리하는 istream 클래스 메서드가 존재하지 않는다.
	string 객체를 처리하는 istream 클래스 메서드가 없기 때문에, istream 클래스의 멤버 함수를 (위장된 표기로) 사용한다.
	(Friend 함수 관련 내용에서 다룸 11장.) */

	return 0;
}