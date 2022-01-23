#include <iostream>
int main()
{
	using std::cout;	// using 선언
	using std::cin;
	using std::endl;
	cout << "정수를 하나 입력하십시오: ";

	int by;
	cin >> by;
	cout << "갱신 크기 " << by << "s:\n";

	for (int i = 0; i < 100; i = i + by)
		cout << i << endl;
	return 0;
}
/* i가 102가 되면 루프를 벗어난다.
여기서 중요한 것은 어떤 표현식도 갱신 표현식으로 사용할 수 있다.
i = i * i + 10과 같은 표현식도 사용이 가능하다. */