#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);

	float tree = 3;			// int형을 float형으로 변환
	int guess = 3.9832;		// float형을 int형으로 변환
	int debt = 7.2E12;		// 결과 예측 불가

	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	return 0;

}

/* 정수형 변수를 부동 소수점형 값으로 초기화할 경우 데이터가 손실될 수 있다.
debt가 출력하는 값은 컴파일러마다 다르다.
*/