#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield); // 고정 소수점 형식으로 출력

	float tub = 10.0 / 3.0; // 유효 숫자 6개
	double mint = 10.0 / 3.0; // 유효 숫자 15개
	const float million = 1.0e6;

	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ",\nten million tubs = ";
	cout << 10 * million * tub << endl;

	cout << "mint = " << mint << "and a million mints = ";
	cout << million * mint << endl;
	return 0;
}

/* const 키워드 : 변수의 상수화.
#define 보다 const를 선호하는 이유
1. 데이터형을 명시적으로 지정
2. C++의 활동 범위 규칙에 의해 특정 함수나 파일에서만 사용할 수 있도록 제한 가능.
3. 배열 구조체와 같은 복잡한 데이터형에서도 사용가능.
*/