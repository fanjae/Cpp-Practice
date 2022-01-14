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
		cout << "잔여 연료량: " << fuelGauge << endl;
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
		cout << "화물의 무게 : " << freightWeight << endl;
	}
};

int main(void)
{
	Car * pcar1 = new Truck(80, 200); 
	Truck * ptruck1 = (Truck *)pcar1; // 문제없이 형변환이 가능하다.
	ptruck1->ShowTruckState(); // 기초 클래스의 포인터 형을 유도 클래스 퐁니터 형으로 형 변환 하는것이 일반적인 형변환은 아니다.
	cout << endl;

	Car * pcar2 = new Car(120);
	Truck * ptruck2 = (Truck *)pcar2; // pcar2가 가리키는 대상이 실제로 car 객체이므로 이 형변환은 문제가 된다.
	ptruck2->ShowTruckState(); // 따라서 이 실행결과는 예측이 불가능하다.
	return 0;
}
