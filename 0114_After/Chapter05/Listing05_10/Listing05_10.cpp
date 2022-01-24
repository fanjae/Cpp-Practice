#include <iostream>
int main()
{
	using namespace std;
	int quizscores[10] = { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };

	cout << "올바른 방법 : \n";
	int i;
	for (i = 0; quizscores[i] == 20; i++)
		cout << i << "번 퀴즈의 점수는 20입니다.\n";
	// 주의 : 직접 프로그램을 실행하지 않아도 문제점을 확인할 수 있다.
	cout << "잘못된 방법:\n";
	for (i = 0; quizscores[i] = 20; i++)
		cout << i << "번 퀴즈의 점수는 20입니다.\n";
	// 조건 검사 표현식의 오류로 인해서 배열의 끝을 벗어나 계속해서 데이터를 변경한다.
	// 구문상으로 코드는 적법하여 컴파일 단계에서는 문제가 되지 않는다.

	return 0;
}