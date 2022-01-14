#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{
	}
	void ShowCarState() {
		cout << "�ܿ� ���ᷮ: " << fuelGauge << endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
	{
	}
	void ShowTruckState()
	{
		ShowCarState();
		cout << "ȭ���� ���� : " << freightWeight << endl;
	}
};

int main(void)
{
	Car * pcar1 = new Truck(80, 200); 
	Truck * ptruck1 = (Truck *)pcar1; // �������� ����ȯ�� �����ϴ�.
	ptruck1->ShowTruckState(); // ���� Ŭ������ ������ ���� ���� Ŭ���� ������ ������ �� ��ȯ �ϴ°��� �Ϲ����� ����ȯ�� �ƴϴ�.
	cout << endl;

	Car * pcar2 = new Car(120);
	Truck * ptruck2 = (Truck *)pcar2; // pcar2�� ����Ű�� ����� ������ car ��ü�̹Ƿ� �� ����ȯ�� ������ �ȴ�.
	ptruck2->ShowTruckState(); // ���� �� �������� ������ �Ұ����ϴ�.
	return 0;
}
