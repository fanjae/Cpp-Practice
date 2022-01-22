#include <iostream>
#include <string>
using namespace std;
struct CandyBar
{
	string Candy_name;
	double kg;
	int kcal;
};
int main()
{
	CandyBar data = { "Mocha Munch", 2.3, 350 };
	cout << "상표명 : " << data.Candy_name << endl;
	cout << "중량 : " << data.kg << "kg" << endl;
	cout << "칼로리 : " << data.kcal << "kcal" << endl;

}