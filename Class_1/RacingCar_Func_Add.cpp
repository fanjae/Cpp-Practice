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
	
	/* 기존 예제와 다르게, Car 구조체의 데이터를 다루는 함수를 모두
	Car 구조체에 종속 시킬 수 있음 */
	 
	void ShowCarState()
	{
		cout << "소유자 ID : " << gamerID << "\n";
		cout << "연료량 : " << fuelGauge << "%" << "\n";
		cout << "현재속도 : " << curSpeed << "km/s" << "\n" << "\n";
	}
	
	void Accel()
	{
		if(fuelGauge <= 0)
		{
			return ;
		}
		else
		{
			fuelGauge -= FUEL_STEP;
		}
		
		if(curSpeed + ACC_STEP >= MAX_SPD)
		{
			curSpeed = MAX_SPD;
			return ;
		}
		
		curSpeed += ACC_STEP;
	}
	void Break()
	{
		if(curSpeed < BRK_STEP)
		{
			curSpeed = 0;
			return ;
		}
		curSpeed -= BRK_STEP;
	}
};

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


