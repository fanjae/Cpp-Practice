#include <iostream>
#include "sales.h"

int main()
{
	using namespace std;
	using namespace SALES;
	Sales a1, a2, a3;

	double test1[2] = { 3.1, 9.7 };
	double test2[4] = { 1.4, 2.5, 3.2, 6.5 };
	setSales(a1, test1, 2);
	setSales(a2, test2, 4);

	showSales(a1);
	showSales(a2);

	cout << endl << endl;

	setSales(a3);
	showSales(a3);

}