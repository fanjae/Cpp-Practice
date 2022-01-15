#include <iostream>
using namespace std;
int main()
{
	using namespace std;
	int chest = 42;		// 10진 정수형 상수
	int waist = 0x42;	// 16진 정수형 상수
	int inseam = 042;	// 8진 정수형 상수

	cout << "가슴둘레 " << chest << "\n";
	cout << "허리둘레 " << waist << "\n";
	cout << "인심길이 " << inseam << "\n";
	return 0;
}

/* cout에 전달하는 dec,hex,oct 조정자를 제공한다.
10진수가 디폴트 형태이다. 각각의 형태는 사용자가 그것을 변경하기 전까지 유지한다. */