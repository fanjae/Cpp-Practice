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

	cout << "Ű�� Feet ������ �Է��ϼ��� : ";
	cin >> Feet;
	cout << "Ű�� Inch ������ �Է��ϼ��� : ";
	cin >> Inch;
	cout << "ü���� Pound�� ������ �Է��ϼ��� : ";
	cin >> Pound;

	double BMI_height = (Feet * FEET + Inch) * METER;
	double BMI_weight = Pound * KG;

	cout << "BMI : " << BMI_weight / (BMI_height * BMI_height) << endl;

}