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
		cout << "��û ������ ����մϴ�." << "\n";
	}
};

class NotebookComp : public Computer // ��Ʈ�� ��ǻ��
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
			cout << "������ �ʿ��մϴ�." << "\n";
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo()
	{
		return Battery;
	}
};

class TableNotebook : public NotebookComp // Ÿ�� ��ǻ��
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
			cout << "������ �ʿ��մϴ�. " << "\n";
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�. " << "\n";
		UseBattery();
	}
};

int main(void)
{

	NotebookComp Fan("������", 5);
	TableNotebook Got("������", 3, "T12-054-321");
	Fan.MovingCal();
	Got.Write("T12-054-321");

	// TableNotebook Ŭ���� ��ü���� ���������� TableNotebook Ŭ������ ����ϴ�
	// NotebookComp�� NoteBookComp Ŭ������ ����ϴ� Computer Ŭ���� �����ڰ� ��� ȣ��ȴ�.

	return 0;
}


