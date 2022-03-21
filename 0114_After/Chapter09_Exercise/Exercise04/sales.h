#pragma once
namespace SALES
{
	const int QUARTERS = 4;
	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales &s, const double ar[], int);
	void setSales(Sales &s);
	void showSales(const Sales &s);
}