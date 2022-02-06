#include <iostream>
using namespace std;

double pointer(double x, double y, double(*)(double, double));
double add(double x, double y);
double min(double x, double y);

int main()
{
	double(*pf[2]) (double, double) = { add, min };
	while (1)
	{
		double x, y;
		int n;
		cout << "두 수 입력 : ";
		if (!(cin >> x >> y))
		{
			break;
		}
		cout << "덧셈 : 0    뺄셈 : 1\n";
		cin >> n;
		double q = pointer(x, y, *pf[n]);
		cout << "결과값 : " << q << endl;
	}
}
double pointer(double x, double y, double(*cal)(double, double))
{
	return (*cal)(x, y);
}
double add(double x, double y)
{
	return x + y;
}
double min(double x, double y)
{
	return x - y;
}