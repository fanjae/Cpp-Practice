#include <iostream>
using namespace std;

namespace CAR_CONST
{
	/* 기존 매크로 상수들이
	구조체 Car에서만 사용되는 상수들이다. */ 
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

struct Car
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
	
	void ShowCarState();
	void Accel();
	void Break(); 
	
};

/* 구조체 안에 함수가 정의되어 있으면 함수를 인라인으로 처리하라고 지정됨.
함수를 구조체 밖으로 빼내면 이러한 의미가 사라짐 */
void Car::ShowCarState()
{
	cout << "소유자 ID : " << gamerID << "\n";
	cout << "연료량 : " << fuelGauge << "%" << "\n";
	cout << "현재속도 : " << curSpeed << "km/s" << "\n" << "\n";
}

void Car::Accel()
{
	if(fuelGauge <= 0)
	{
		return ;
	}
	else
	{ 
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}
	
	if((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return ;
	}
	
	curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break()
{
	if(curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return ;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}
int main(void)
{
	Car run99={"run99",100,0};
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	
	Car sped77={"sped77",100,0};
	sped77.Accel();
	sped77.Break();
	sped77.ShowCarState();
	return 0;	
}


