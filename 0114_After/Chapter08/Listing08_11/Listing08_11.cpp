#include <iostream>
// 함수 템플릿 원형
template <class Any>			// 또는 typename Any
void Swap(Any &a, Any &b);
/* 함수 템플릿은 데이터형을 바꾸는 과정과 같은 행위를 자동화하여
코드의 신뢰성을 높여준다.
함수 템플릿은 임의 데이터형으로 함수를 정의하는 것을 허용한다.

첫 번째 행은 템플릿을 설정하고, 임의 데이터형의 이름을 Any로 정한다는 뜻이다.
키워드 template과 class(class 대신 typename을 써도 된다)를 반드시 사용해야 한다.
임의 데이터형의 이름(Any)는 C++의 이름짓기 규칙만 바르게 준수하면 아무것이나 사용 가능하다. 
*/

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);					// void Swap(int &, int &)를 생성한다.
	cout << "이제 i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "컴파일러가 생성한 double형 교환기를 사용하면\n";
	Swap(x, y);					// void Swap(double &, double &)를 생성한다.
	cout << "이제 x, y = " << x << ", " << y << ".\n";
	// cin.get();
	return 0;
}


// 함수 템플릿 정의
template <class Any>			// 또는 typename Any
void Swap(Any &a, Any &b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}