#include <iostream>
#include <new>
using namespace std;

int main(void)
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			cout << num << "번째 할당 시도" << endl;
			new int[10000][10000]; // 메모리 할당 관련 예외를 발생을 위해서 반복해서 메모리 공간을 할당만 하고 있다.
		}
	}
	catch (bad_alloc &bad) // 예외의 발생을 확인하기 위한 catch 블록이다.
	{
		cout << bad.what() << endl; // what 함수는 예외의 원인 정보를 문자열의 형태로 반환함. 
		cout << "더 이상 할당 불가!" << endl; // 반환 문자열의 내용은 컴파일러에 따라서 달라진다.
	}
	return 0;
}