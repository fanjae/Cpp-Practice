#include <iostream>
using namespace std;
int main(void)
{
	int angle, min_angle, sec_angle;
	const double Minutes = 60;
	const double Seconds = 60;
	
	cout << "위도를 도, 분, 초 단위로 입력하세요: " << endl;
	cout << "먼저, 도각을 입력하시오 : ";
	cin >> angle;
	cout << "다음에, 분각을 입력하시오 : ";
	cin >> min_angle;
	cout << "끝으로, 초각을 입력하시오 : ";
	cin >> sec_angle;

	double answer_Angle = angle + (min_angle / Minutes) + (sec_angle / Seconds) / 60;
	cout << angle << "도, " << min_angle << "분, " << sec_angle << "초 = " << answer_Angle << "도";


}