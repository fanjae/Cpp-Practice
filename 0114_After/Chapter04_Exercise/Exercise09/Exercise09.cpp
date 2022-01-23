#include <iostream>
#include <string>

using namespace std;

struct Pizza
{
	string company_name;
	double diameter;
	double kg;
};

int main()
{
	Pizza *company_list[3];
	
	company_list[0] = new Pizza();
	company_list[1] = new Pizza();
	company_list[2] = new Pizza();
	
	company_list[0]->company_name = "Domino Pizza";
	company_list[0]->diameter = 1.5;
	company_list[0]->kg = 2.3;

	company_list[1]->company_name = "Mister Pizza";
	company_list[1]->diameter = 1.5;
	company_list[1]->kg = 2.3;

	company_list[2]->company_name = "Pizza Hut";
	company_list[2]->diameter = 1.5;
	company_list[2]->kg = 2.3;
}