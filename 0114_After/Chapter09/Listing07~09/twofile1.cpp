#include <iostream>
int tom = 3;
int dick = 30;
static int harry = 300;

// 함수 원형
void remote_access();

int main()
{
	using namespace std;
	cout << "main()이 보고하는 세 변수의 주소 : \n";
	cout << &tom << " = &tom, " << &dick << " = &dick, ";
	cout << &harry << " = &harry\n";
	remote_access();
	return 0;
}
