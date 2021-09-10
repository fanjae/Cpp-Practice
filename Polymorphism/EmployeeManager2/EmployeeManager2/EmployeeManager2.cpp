#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

class Employee // ������� �ǹ��ϴ� Employee Ŭ���� �߰�
{
private:
	char name[100];
public:
	Employee(const char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << "\n";
	}
};

class PermanentWorker : public Employee // Employee Ŭ������ ����ϵ��� ����
{
private:
	int salary;			// �Ŵ� �����ؾ� �ϴ� �޿���
public:
	PermanentWorker(const char *name, int money) : Employee(name), salary(money)
	{

	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << "\n" << "\n";
	}
};

class EmployeeHandler
{
private:
	Employee *empList[50]; // ���� PermanentWorker ��ü���� Employee ��ü�� ����Ǿ���. PermanentWorker ��ü ���� Employee ��ü�� �����̹Ƿ� ������ �����ϴ�.
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{
	}
	void AddEmployee(Employee *emp) // Employee ��ü�� �ּҰ��� �����ؾ� �Ѵ�. ����, Employee Ŭ������ ����ϴ� PermanentWorker ��ü �ּҰ� ���޵� �����ϴ�.
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		/* Compile Error�� ���� �ּ�ó��
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/* Compile Error�� ���� �ּ�ó��
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		*/
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

}