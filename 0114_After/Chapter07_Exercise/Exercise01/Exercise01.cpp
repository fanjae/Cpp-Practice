#include <iostream>
using namespace std;
double func(double x, double y);
int main()
{
	double x, y;
	do
	{
		cout << "x값 입력 : ";
		cin >> x;
		cout << "y값 입력 : ";
		cin >> y;

		if (x != 0 && y != 0)
		{
			cout << "조화평균 : " << func(x, y) << endl;
		}
	} while (x != 0 && y != 0);
}
double func(double x, double y)
{
	return 2.0 * x * y / (x + y);
}