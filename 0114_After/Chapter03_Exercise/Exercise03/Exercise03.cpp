#include <iostream>
using namespace std;
int main(void)
{
	int angle, min_angle, sec_angle;
	const double Minutes = 60;
	const double Seconds = 60;
	
	cout << "������ ��, ��, �� ������ �Է��ϼ���: " << endl;
	cout << "����, ������ �Է��Ͻÿ� : ";
	cin >> angle;
	cout << "������, �а��� �Է��Ͻÿ� : ";
	cin >> min_angle;
	cout << "������, �ʰ��� �Է��Ͻÿ� : ";
	cin >> sec_angle;

	double answer_Angle = angle + (min_angle / Minutes) + (sec_angle / Seconds) / 60;
	cout << angle << "��, " << min_angle << "��, " << sec_angle << "�� = " << answer_Angle << "��";


}