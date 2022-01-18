#include <iostream>
struct inflatable	// 구조체 선언
{
	char name[20];
	float volume;
	double price;
};

/* 위와 같이 함수의 밖에 선언을 두는 것을 외부 선언(External Declaration)이라고 한다.
외부 선언은 선언 이후에 나오는 모든 함수들이 사용할 수 잇으나,
내부 선언은 그 선언이 들어있는 함수에서만 사용할 수 있다.
*/


int main()
{
	using namespace std;
	inflatable guest =
	{
		"Glorious Gloria",  // name 값
		1.88,				// volume 값
		29.99				// price 값
	};						// guest는 inflatable형의 구조체 변수이다.

	// 지정된 값으로 초기화

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};						// pal는 inflatable형의 두 번째 수이다.

// 참고 : 어떤 C++ 시스템에서는 아래와 같은 형식을 요구한다.
// static inflatable guest =

	cout << "지금 판매하고 있는 모형풍선은\n" << guest.name;
	cout << "와 " << pal.name << "입니다.\n";
	// pal.name은 pal 변수의 name 멤버이다.

	cout << "두 제품을 $";
	cout << guest.price + pal.price << "에 드리겠습니다!\n";
	return 0;
}

/*
C++11에서는 구조체를 초기화 할때 =을 생략할 수 있다.
*/