#include <iostream>
using namespace std;

template <typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	cout << num << " ";
}

int main(void)
{
	ShowStaticValue<int>(); 
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout << endl;
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	cout << endl;
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();

	// 실행해보면 템플릿 함수 별로, static 지역변수가 유지됨을 알 수 있다.
	return 0;
}