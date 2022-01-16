#include <iostream>
#include <cstring> // string() 함수 사용을 위한 헤더 선언
int main()
{
	using namespace std;
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	// 참고 : 어떤 C++에서는 name2 배열을 초기화 하기 위해서 static을 사용해야 한다.

	cout << "안녕하세요! 저는 " << name2;
	cout << "입니다! 실례지만 성함이?\n";
	cin >> name1;

	cout << "아, " << name1 << " 씨! 당신의 이름은 ";
	cout << strlen(name1) << "자입니다만 \n";
	cout << sizeof(name1) << "바이트 크기의 배열에 저장되었습니다.\n";
	cout << "이름이 " << name1[0] << "자로 시작하는군요.\n";
	name2[3] = '\0';		// NULL 문자
	cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
	cout << name2 << endl;

	return 0;
}

/* name1과 name2는 배열이므로, 인덱스를 사용하여 그 배열에 저장되어있는
문자들에 개별적으로 접근이 가능하다.
'\0'을 이용하여 널 문자로 설정하면 이후 인덱스에 다른 문자가 존재하더라도
문자열을 끝내게 된다. */