#include <iostream>

using namespace std;
class Car
{
private:
	int gasonlineGauge;
public:
	Car(int n1) : gasonlineGauge(n1)
	{

	}
	int GetGasGauge()
	{
		return gasonlineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int n1, int n2) : Car(n1), electricGauge(n2)
	{

	}
	int GetElecGuage()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int n1, int n2, int n3) : HybridCar(n1, n2), waterGauge(n3)
	{

	}
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸° : " << GetGasGauge() << "\n";
		cout << "ÀÜ¿© Àü±â·® : " << GetElecGuage() << "\n";
		cout << "ÀÜ¿© ¿öÅÍ·® : " << waterGauge << "\n";
	}
};

int main(void)
{
	HybridWaterCar wCar(79, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}