#include <iostream>
int main()
{
	using namespace std;
	int nights = 1001;
	int *pt = new int;				// int형을 저장할 메모리를 대입
	/*
	new 연산자를 이용하면, 몇 바이트가 필요한지 파악하고
	적당한 메모리를 찾아 필요한 만큼 블록을 대입하고, 그 주소를 리턴한다.
	리턴되는 주소는 int형을 지시하는 포인터로 대입된다.
	*/

	*pt = 1001;						// 대입된 메모리에 값을 저장.

	cout << "nights의 값 = ";
	cout << nights << " : 메모리 위치 " << &nights << endl;
	cout << "int 형";
	cout << "값 = " << *pt << ": 메모리 위치 = " << pt << endl;

	double *pd = new double;		// double형을 저장할 메모리를 대입.
	*pd = 10000001.0;				// 그 메모리에 double형 값을 저장.

	cout << "double 형";
	cout << "값 = " << *pd << ": 메모리 위치 = " << pd << endl;
	cout << "포인터 pd의 메모리 위치: " << &pd << endl;
	cout << "pt의 크기 = " << sizeof(pt);
	cout << ": *pt의 크기 = " << sizeof(*pt) << endl;
	cout << "pd의 크기 = " << sizeof pd;
	cout << ": *pd의 크기 = " << sizeof(*pd) << endl;

	return 0;
}

/* 컴퓨터에 사용할 수 있는 메모리가 부족하여 new의 메모리 대입 요청을 허용할 수 없는 상황이 발생할 수 있다.
이 경우 new는 0을 리턴한다. 값이 0인 포인터를 Null Pointer라고 부른다.
널 포인터는 어떠한 데이터도 지시하지 않는다. */

