#include <iostream>
#include <cstring>
#include "inlineCar.h"
using namespace std;

// InitMembers : �ʱ�ȭ�� ���� �Լ� 
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

/* inline �Լ��� ����� ���� ������Ͽ� �Բ� �־�� �Ѵ�.
inline �Լ��� Ư¡ ������ �Լ��� ȣ�⹮���� �Լ��� ��ü�� ��ü�Ǿ�� �Ѵ�. */ 
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
