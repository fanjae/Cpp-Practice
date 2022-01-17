#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름을 입력하십시오:\n";
	cin >> name;
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin >> dessert;
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << " 님\n";
	return 0;
}

/* 입력 예시 : Alistair Dreeb */
/* 이 프로그램은 디저트를 입력하라는 프롬프트에 응답할 기회를 주지 않는다.
디저트를 입력하라는 프롬프트 출력 이후 마지막 줄까지 출력해버린다.
cin의 문자열 끝을 인식하는 방법 때문이다.
키보드로는 널 문자 입력을 할 수 없어, 문자열 끝을 알려줄 수단이 필요하다.

cin은 빈칸, 탭, 캐리지 리턴과 같은 화이트스페이스가 있으면 문자열이 끝난 것으로 간주한다. */

