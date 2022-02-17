#include <iostream>
#pragma warning (disable:4996)
struct CandyBar
{
	char name[100];
	double kg;
	int kcal;
};

void Set_CandyBar(CandyBar &value, const char Name[100] = { "Millennium Munch" }, double Kg = 2.85, int Kcal = 350);
int main()
{
	using namespace std;

	CandyBar data;
	Set_CandyBar(data);

	cout << "상표명 : " << data.name << endl;
	cout << "중량 : " << data.kg << endl;
	cout << "칼로리 : " << data.kcal << endl;
}
void Set_CandyBar(CandyBar &value, const char Name[100],double Kg,int Kcal)
{
	strcpy(value.name, Name);
	value.kg = Kg;
	value.kcal = Kcal;
}