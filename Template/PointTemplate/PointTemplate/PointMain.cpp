#include <iostream>
#include "PointTemplate.h"
#include "PointTemplate.cpp" // 클래스 템플릿인 Point에 대한 정보 부족으로 발생한다.
// 따라서, 헤더파일에 Point 생성자와 멤버함수의 정의를 모두 넣거나, .cpp를 포함시켜야 한다.
using namespace std;

int main(void)
{
	Point <int> pos1(3, 4);
	pos1.ShowPosition();

	Point <double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point <char> pos3('P', 'F');
	pos3.ShowPosition();
	return 0;
}