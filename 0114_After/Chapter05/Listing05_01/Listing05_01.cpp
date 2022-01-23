#include <iostream>
int main(void)
{
	using namespace std;
	int i;		// 카운터를 선언한다.
	// 초기화; 조건 검사; 갱신
	for (i = 0; i < 5; i++)
		cout << "C++가 루프를 사용합니다.\n";
	cout << "루프를 언제 끝내야 하는지 C++는 알고 있습니다.\n";
	return 0;
}

/* for 루프는 단계적인 처리를 통해 반복 작업을 수행.
1.조건 검사에 사용할 카운터 값 초기화
2.루프를 진행할 것인지 조건을 검사
3.루프 몸체를 수행한다.
4.카운터 값을 갱신한다.
// 초기화(Initialization), 조건 검사(test), 갱신(Update)를 처리하는 for 루프의
세 제어 부분은 괄호로 묶임. 이들은 하나의 표현식이며, 세미콜론에 의해 분리됨.
*/