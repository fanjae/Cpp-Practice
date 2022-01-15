#include <iostream>
#define ZERO 0		// 값 0으로 대체될 기호 상수 ZERO를 정의
#include <climits>	// INT_MAX가 int형의 최대값으로 정의
int main()
{
	using namespace std;
	short Dohee = SHRT_MAX;
	unsigned short Insuk = Dohee;

	cout << "도희의 계좌에는 " << Dohee << "원이 들어 있고, ";
	cout << "인숙이의 계좌에도 " << Insuk << "원이 들어 있다." << endl;
	cout << "각각의 계좌에 1원씩 입금한다." << endl << "이제 ";
	Dohee = Dohee + 1;
	Insuk = Insuk + 1;
	cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << Insuk << "원이 되었다." << endl;
	cout << "이럴 수가! 도희가 나 몰래 대출을 했나?" << endl << endl;

	Dohee = ZERO;
	Insuk = ZERO;
	cout << "도희의 계좌에는 " << Dohee << "원이 들어 있고, ";
	cout << "인숙이의 계좌에도 " << Insuk << "원이 들어 있다." << endl;
	cout << "각각의 계좌에 1원씩 입금한다." << endl << "이제 ";

	Dohee = Dohee + 1;
	Insuk = Insuk + 1;
	cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << Insuk << "원이 되었다." << endl;
	cout << "이럴 수가! 인숙이가 복권에 당첨되었나?" << endl << endl;
	return 0;
}

/* short 형의 최대 값 32,767(현 시스템 기준) Insuk 변수는 +1을 해도 문제되지 않음.
최대값이 65,535보다 작다. 하지만 Dohee는 32,767dptj -32,768로 갑자기 넘어간다.
unsigned short 형인 Insuk에서 1을 빼면 0에서 65,535로 갑자기 넘어간다.

즉, 표현할 수 있는 한계를 벗어나면 그 표현 범위의 반대편에서부터 다시 시작한다. */
