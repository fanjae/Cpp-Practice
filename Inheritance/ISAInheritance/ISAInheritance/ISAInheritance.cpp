#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char *name)
	{
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "요청 내용을 계산합니다." << "\n";
	}
};

class NotebookComp : public Computer // 노트북 컴퓨터
{
private:
	int Battery;
public:
	NotebookComp(const char *name, int initChag) : Computer(name), Battery(initChag)
	{

	}
	void Charging()
	{
		Battery += 5;
	}
	void UseBattery()
	{
		Battery -= 1;
	}
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다." << "\n";
		}
		cout << "이동하면서 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo()
	{
		return Battery;
	}
};

class TableNotebook : public NotebookComp // 타블렛 컴퓨터
{
private:
	char regstPenModel[50];
public:
	TableNotebook(const char *name, int initChag, const char * pen) : NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void Write(const char *penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "충전이 필요합니다. " << "\n";
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다. " << "\n";
		UseBattery();
	}
};

int main(void)
{

	NotebookComp Fan("김진우", 5);
	TableNotebook Got("이종윤", 3, "T12-054-321");
	Fan.MovingCal();
	Got.Write("T12-054-321");

	// TableNotebook 클래스 객체생성 과정에서는 TableNotebook 클래스가 상속하는
	// NotebookComp와 NoteBookComp 클래스가 상속하는 Computer 클래스 생성자가 모두 호출된다.

	return 0;
}


