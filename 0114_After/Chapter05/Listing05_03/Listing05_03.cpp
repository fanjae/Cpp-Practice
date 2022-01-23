#include <iostream>
int main()
{
	using namespace std;
	int x;

	cout << "대입 표현식 x = 100의 값은 ";
	cout << (x = 100) << endl;
	cout << "현재 x의 값은 " << x << endl;
	cout << "관계 표현식 x < 3의 정수값은 ";
	cout << (x < 3) << endl;
	cout << "관계 표현식 x > 3의 정수값은 ";
	cout << (x > 3) << endl;
	cout.setf(ios_base::boolalpha);			// 최신 C++ 기능

	cout << "관계 표현식 x < 3의 bool값은 ";
	cout << (x < 3) << endl;
	cout << "관계 표현식 x > 3의 bool값은 ";
	cout << (x > 3) << endl;

	return 0;
}

/* 관계 표현식은 bool값인 true나 false로 평가된다.
이는 각각 1과 0으로 출력된다.
cout.setf(ios_base::boolalpha) 함수 호출이 있으면,
true,false를 출력한다. */