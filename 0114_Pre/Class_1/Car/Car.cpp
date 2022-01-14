#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;


// InitMembers : 초기화를 위한 함수 
void Car::InitMembers(char *ID, int fuel)
{
	strcpy(gamerID,ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

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
	Car run99;
	run99.InitMembers("run99",100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}
