#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	/*
	cin.get(name, ArSize);
	cin.get(dessert, Arsize);		// 문제 발생
	첫 번째 호출이 입력 큐에 개행 문자를 그대로 남겨두기 때문에, 두번째 호출에서
	그 개행 문자를 첫 문자로 만나게된다.
	// cin.get()은 개행 문자이든 아니면 다른 무엇이든 무조건 문자 하나를 읽는다.


	cin.get(name, Arsize);			// 첫 번째 행을 읽는다.
	cin.get();						// 개행 문자를 읽는다.
	cin.get(dessert, ArSize);		// 두 번째 행을 읽는다.

	*/
	
	cout << "이름을 입력하십시오:\n";
	cin.get(name, ArSize).get();			// 문자열, 개행 문자를 읽는다.
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin.get(dessert, ArSize).get();	
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << "님!\n";
	
	// 매개변수 리스트가 없는 cin.get()을 사용하면 컴파일러는 문자 하나를 읽으라는 뜻으로 받아들인다.
	return 0;
}