#include <iostream>
using namespace std;

void Client();

// 서버 //
void PrintHello()
{
	cout << "Hello!" << endl;
	Client(); // Server 에서 Client 호출
}

// 클라이언트 //
void Client()
{
	cout << "I'm Client" << endl;
}

int main()
{
	PrintHello(); // 서버 코드 호출.
	return 0;
}

// PrintHello) 함수인 서버에서 클라이언트 측 코드인 Client() 함수 호출.
// 이때 Client() 함수를 '콜백 함수'라고 함.