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
	void ShowCarState()
	{
		cout << "잔여 연료량 : " << fuelGauge << endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight) :Car(fuel), freightWeight(weight)
	{

	}
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게 : " << freightWeight << endl;
	}
};

int main(void)
{
	Car *pcar1 = new Truck(80, 200);
	Truck * ptruck1 = static_cast<Truck *>(pcar1); // pcar1을 Truck의 포인터 형으로 변환함.
	ptruck1->ShowTruckState();
	cout << endl;

	Car *pcar2 = new Car(120);
	Truck * ptruck2 = static_cast<Truck *>(pcar2); // 컴파일은 가능하나 문제가 존재함.
	ptruck2->ShowTruckState();

	// static_cast 연산자는 dynamic_cast 연산자와 달리, 보다 많은 형 변환을 허용함.
	// 단, 이에 따른 책임 또한 프로그래머에게 있으므로, 신중한 선택이 필요하다.
	// dynamic_cast 연산자를 사용할 수 있는 경우 이를 이용해 안전성을 높여야 한다.
	// 정말 제한 적인 상황에서만 제한적으로 static_cast를 사용함.
	return 0;
}
