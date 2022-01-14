#include <iostream>
#include <cstring>
#include "inlineCar.h"
using namespace std;

// InitMembers : 초기화를 위한 함수 
void Car::InitMembers(char *ID, int fuel)
{
	strcpy(gamerID,ID);
	fuelGauge = fuel;
	curSpeed = 0;
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

/* inline 함수를 사용할 때는 헤더파일에 함께 넣어야 한다.
inline 함수의 특징 때문에 함수의 호출문장이 함수의 몸체로 대체되어야 한다. */ 
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
