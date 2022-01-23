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
	Pizza company1;
	cout << "회사 이름 : ";
	getline(cin, company1.company_name);
	cout << "피자의 지름 : ";
	cin >> company1.diameter;
	cout << "피자의 중량 : ";
	cin >> company1.kg;

	cout << "회사 이름 : " << company1.company_name << endl;
	cout << "피지의 지름 : " << company1.diameter << endl;
	cout << "피자의 중량 : " << company1.kg << endl;
}