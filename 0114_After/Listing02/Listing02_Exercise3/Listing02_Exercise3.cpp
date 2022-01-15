// CHAPTER 02 EX.3
#include <iostream>
using namespace std;

void fun1() // 사용자 정의 함수 1
{
	cout << "Three blind mice" << endl;
}
void fun2() // 사용자 정의 함수 2
{
	cout << "See how they run" << endl;
}

int main()
{
	fun1();
	fun1();
	fun2();
	fun2();
}