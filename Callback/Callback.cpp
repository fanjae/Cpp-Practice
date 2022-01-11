// Callback 예제 //

#include <iostream>
using namespace std;

// Server //

typedef void(*CALLBACK_FUNC)(int); // 함수 포인터

CALLBACK_FUNC cbf = NULL; // Callback function을 다루기 위한 전역 변수

void RegistCallback(CALLBACK_FUNC cb)
{
	cbf = cb;
}

void StartCallback() // 콜백 테스트를 위한 함수
{
	if (cbf == NULL)
	{
		cout << "Callback Function is not Registed" << endl;
		return;
	}
	cout << "Server calls CB." << endl;
	cbf(1); // 서버 측에 등록된 콜백함수 호출 / 인자로 1을 전달.
}

// Client //
void UserCallback(int n)
{
	if (n == 1)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}

int main()
{
	// Client //
	RegistCallback(UserCallback); // Callback 등록

	// Server //
	StartCallback();

	// 순서
	// 1. Callback 등록 함수를 호출.
	// 2. Callback 함수를 호출.
	return 0;
}
