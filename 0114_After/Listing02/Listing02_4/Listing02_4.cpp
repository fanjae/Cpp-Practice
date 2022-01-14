#include <iostream>
#include <cmath> // math.h

int main()
{
	using namespace std;

	double area;
	cout << "마루 면적을 평방피트 단위로 입력하시오 : ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "사각형 마루라면 한 변이 " << side << "피트에 상당합니다." << endl;
	cout << "멋지네요!" << endl;
	return 0;

	/* cin은 입력 스트림에서 가져온 정보를 double형으로 변환하는 방법을 알고 있다.
	또한, cout은 double형 정보를 출력 스트림에 삽입하는 방법을 알고 있다.
	cin과 cout이 똑똑한 객체이기 때문이다. */


}
