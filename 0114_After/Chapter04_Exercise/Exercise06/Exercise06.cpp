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
	CandyBar data[5] = {
		{"Twix",0.5,200},
		{"Snickers",0.6,250},
		{"자유시간",0.4,180},
		{"핫브레이크",0.7,300},
		{"아트라스",0.3,150}};

	cout << "상표명 : " << data[0].Candy_name << endl;
	cout << "중량 : " << data[0].kg << "kg" << endl;
	cout << "칼로리 : " << data[0].kcal << "kcal" << endl;

	cout << "상표명 : " << data[1].Candy_name << endl;
	cout << "중량 : " << data[1].kg << "kg" << endl;
	cout << "칼로리 : " << data[1].kcal << "kcal" << endl;

	cout << "상표명 : " << data[2].Candy_name << endl;
	cout << "중량 : " << data[2].kg << "kg" << endl;
	cout << "칼로리 : " << data[2].kcal << "kcal" << endl;

}