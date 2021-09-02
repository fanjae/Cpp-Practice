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
�Ʒ� �ۼ��� ��� �Լ��� Car�� ���õ� �����͸� ó���ϴ� �Լ��̴�.
������, �����Լ� �����̹Ƿ�, Car�� ���������� �ʴ�. 
�̿� ����, Car�� ���������� ������ �Ѵ�. 
*/
void ShowCarState(const Car &car) // ������ �����ִ� �Լ��� const �����ڸ� �Ű������� ���. 
{
	cout << "������ ID : " << car.gamerID << "\n";
	cout << "���ᷮ : " << car.fuelGauge << "%" << "\n";
	cout << "����ӵ� : " << car.curSpeed << "km/s" << "\n" << "\n";
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

void Break(Car &car) // �극��ũ�� ���� ��Ȳ�� ǥ��. 
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

