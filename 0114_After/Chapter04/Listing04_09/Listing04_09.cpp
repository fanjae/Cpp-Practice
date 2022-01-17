#include <iostream>
#include <string>					// string 클래스를 사용하기 위해
#include <cstring>					// C 스타일 문자열 라이브러리

#pragma warning(disable:4996) // strcpy & strcat 관련 Warning 무시
int main()
{
	using namespace std;

	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	// string 객체의 대입과 문자 배열의 대입
	str1 = str2;					// str2를 str1에 복사
	strcpy(charr1, charr2);			// charr2를 charr1에 복사

	// string 객체의 추가와 문자 배열의 추가
	str1 += " paste";				// str1의 끝에 paste를 추가
	strcat(charr1, " juice");		// charr1의 끝에 juice를 추가

	// string 객체의 길이 구하기와 C 스타일 문자열의 길이를 구하기
	int len1 = str1.size();			// str1의 길이를 구한다.
	int len2 = strlen(charr1);		// charr1의 길이를 구한다.

	cout << str1 << " 문자열에는 " << len1 << "개의 문자가 들어있다.\n";
	cout << charr1 << "문자열에는 " << len2 << "개의 문자가 들어있다.\n";

	/* C 라이브러리는 strcat(),strcpy() 外 strncpy(),strncpy()를 제공한다.
	이들은 타깃 배열의 최대 허용 크기를 나타내는 매개변수를 사용하여 안전하게 동작한다.

	이와 반면, string 클래스는 필요하면 크기를 자동으로 조절하여 문제를 피한다. */

	/* strlen() 함수는 C스타일 문자열을 매개변수로 사용한다.
	이와 반면 size()는 string 메서드이다. */

	return 0;
}