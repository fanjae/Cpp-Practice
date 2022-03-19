#include <iostream>
#include "sales.h"
using namespace std;

namespace SALES
{
	void setSales(Sales &s, const double ar[], int n)
	{
		s.average = 0;
		if (n < 4)
		{
			for (int i = 0; i < 4; i++)
			{
				s.sales[i] = 0;
			}
		}
		else
		{
			n = 4;
		}
		for (int i = 0; i < n; i++)
		{
			s.sales[i] = ar[i];
		}
		s.max = s.min = s.sales[0];
		s.average += s.sales[0];

		for (int i = 1; i < n; i++)
		{
			if (s.sales[i] > s.max)
			{
				s.max = s.sales[i];
			}
			if (s.sales[i] < s.min)
			{
				s.min = s.sales[i];
			}
			s.average += s.sales[0];
		}
		s.average /= n;
	}
		void setSales(Sales &s)
		{
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1 << "분기별 판매액 : ";
				cin >> s.sales[i];
			}
			s.max = s.min = s.average = s.sales[0];
			for (int i = 1; i < 4; i++)
			{
				if (s.sales[i] > s.max)
				{
					s.max = s.sales[i];
				}
				if (s.sales[i] < s.min)
				{
					s.min = s.sales[i];
				}
				s.average += s.sales[i];
			}
			s.average /= 4;
		}
		void showSales(const Sales &s)
		{
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1 << "분기 판매액 : " << s.sales[i] << endl;
			}
			cout << "최대값 : " << s.max << endl;
			cout << "최소값 : " << s.min << endl;
			cout << "평균값 : " << s.average << endl;
		}
	}
