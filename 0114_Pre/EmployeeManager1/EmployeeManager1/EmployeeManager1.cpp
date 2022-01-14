#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;
class PermanentWorker
{
private:
	char name[100];
	int salary;			// �Ŵ� �����ؾ� �ϴ� �޿���
public:
	PermanentWorker(const char *name, int money) : salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name : " << name << "\n";
		cout << "salary : " << GetPay() << "\n" << "\n";
	}
};

class EmployeeHandler
{
private:
	PermanentWorker *empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{
	}
	void AddEmployee(PermanentWorker *emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		cout << "salary sum : " << sum << "\n";
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main(void)
{
	// ���� ���� �������� ����� ��Ʈ�� Ŭ���� ��ü ����
	EmployeeHandler handler;


	// ���� ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// �̹� �޿� �����ؾ� �� �޿� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;

	/*
	����Ʈ���� ���迡�� �䱸������ ���濡 �����ϴ� ���α׷��� �������̳�
	����� �߰��� ���� ���α׷��� Ȯ������ �ʿ��ϴ�.

	���� ������ �߰����� Ȯ������ ���ؼ� Ŭ������ �߰��� ���� ������ �ּ�ȭ�ϱ� ��ƴ�.
	����, �̷� �κп� ���� ��ġ�� �ʿ��ϴ�.
	*/
}
