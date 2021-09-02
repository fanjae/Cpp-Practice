#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
};

/* 
아래 작성된 모든 함수는 Car와 관련된 데이터를 처리하는 함수이다.
하지만, 전역함수 형태이므로, Car에 종속적이지 않다. 
이에 따라서, Car에 종속적으로 만들어야 한다. 
*/
void ShowCarState(const Car &car) // 정보를 보여주는 함수로 const 참조자를 매개변수로 사용. 
{
	cout << "소유자 ID : " << car.gamerID << "\n";
	cout << "연료량 : " << car.fuelGauge << "%" << "\n";
	cout << "현재속도 : " << car.curSpeed << "km/s" << "\n" << "\n";
}

void Accel(Car &car)
{
	if(car.fuelGauge <= 0)
	{
		return ;
	}
	else
	{
		car.fuelGauge -= FUEL_STEP;
	}
	
	if(car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return ;
	}
	
	car.curSpeed += ACC_STEP;
}

void Break(Car &car) // 브레이크를 밟은 상황을 표현. 
{
	if(car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return ;
	}
	
	car.curSpeed -= BRK_STEP;
}

int main(void)
{
	Car run99 = {"run99",100,0};
	Accel(run99);
	Accel(run99);
	
	ShowCarState(run99);
	Break(run99);
	ShowCarState(run99);
	
	Car sped77={"sped77",100,0};
	Accel(sped77);
	Break(sped77);
	ShowCarState(sped77);
	return 0;
}

