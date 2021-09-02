#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;


// InitMembers : �ʱ�ȭ�� ���� �Լ� 
void Car::InitMembers(char *ID, int fuel)
{
	strcpy(gamerID,ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "������ ID : " << gamerID << "\n";
	cout << "���ᷮ : " << fuelGauge << "%" << "\n";
	cout << "����ӵ� : " << curSpeed << "km/s" << "\n" << "\n";
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
