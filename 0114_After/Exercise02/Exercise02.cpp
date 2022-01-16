#include <iostream>
using namespace std;
int main()
{
	const double FEET = 12; // 1 FEET = 12inch;
	const double KG = 2.2;  // 1 KG = 2.2Pound;
	const double METER = 0.0254; // 1 INCH = 0.0254m

	double Feet;
	double Inch;
	double Pound;

	cout << "키를 Feet 단위로 입력하세요 : ";
	cin >> Feet;
	cout << "키를 Inch 단위로 입력하세요 : ";
	cin >> Inch;
	cout << "체중을 Pound를 단위로 입력하세요 : ";
	cin >> Pound;

	double BMI_height = (Feet * FEET + Inch) * METER;
	double BMI_weight = Pound * KG;

	cout << "BMI : " << BMI_weight / (BMI_height * BMI_height) << endl;

}