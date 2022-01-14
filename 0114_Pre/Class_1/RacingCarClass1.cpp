#include <iostream>
#include <cstring>

using namespace std;
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car
{
	/*
	private 으로 지정된 변수와 함수는 해당 클래스 내에서만 접근이 가능하다.
	*/ 
	private:
		char gamerID[CAR_CONST::ID_LEN];
		int fuelGauge;
		int curSpeed;
		
	/*
	public 으로 지정된 변수와 함수는 어디서든 접근이 가능하다. 
	*/
	public:
		void InitMembers(char *ID, int fuel);
		void ShowCarState();
		void Accel();
		void Break();
};

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
