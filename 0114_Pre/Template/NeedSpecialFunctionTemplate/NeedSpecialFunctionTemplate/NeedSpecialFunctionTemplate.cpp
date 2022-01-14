#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;
	return 0;

	// 두 데이터 중 큰 값을 반환한다.
	// 단, 문자열을 대상으로 할 경우 아무런 의미가 없어진다. (주소값의 비교 결과 이므로,)
	// 따라서, 이러한 경우와 같은 경우 구성방법에 예외를 둬야한다.
}