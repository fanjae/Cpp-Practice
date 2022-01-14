#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

namespace RISK_LEVEL
{
	enum { RISK_A=30, RISK_B=20, RISK_C=10 };
}
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
	virtual int GetPay() const = 0;				// ���� ���� ���ǵǸ� ���� ���� �Լ��̴�.
	virtual void ShowSalaryInfo() const = 0;	// ���� ���� ���ǵǸ� ���� ���� �Լ��̴�.
	/* ���� ���� �Լ��� �Լ��� ��ü�� ���ǵ��� ���� �Լ��̴�.
	���� ���� �Լ��� ����, �������� ���� Ŭ������ �Ǳ� ������,
	�� ��ü�� �����Ϸ� ��� ������ ������ �߻��Ѵ�. */
};

class PermanentWorker : public Employee // Employee Ŭ������ ����ϵ��� ����
{
private:
	int salary;			// �Ŵ� �����ؾ� �ϴ� �޿���
public:
	PermanentWorker(const char *name, int money) : Employee(name), salary(money)
	{

	}
	int GetPay() const // Employee Ŭ������ GetPay�� ShowSalaryInfo �Լ��� �߰��� �����ϰ� �����Լ��� ������.
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

class TemporaryWorker : public Employee // �ӽ���
{
private:
	int workTime;		// �� �޿� ���� �ð��� �հ�
	int payPerHour;		// �ð��� �޿�
public:
	TemporaryWorker(const char *name, int pay) : Employee(name), workTime(0), payPerHour(pay)
	{

	}
	void AddWorkTime(int time)	// ���� �ð��� �߰�
	{
		workTime += time;
	}
	virtual int GetPay() const 	// �� ���� �޿�
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const
	{
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;		// �� �ǸŽ���
	double bonusRatio;		// �󿩱� ����
public:
	SalesWorker(const char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{

	}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio); // PermanentWorker�� GetPay �Լ� ȣ��
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary : " << GetPay() << "\n" << "\n";
	}
	// PermanentWorker�� ��������ν� �⺻ �޿��� ���õ� �κ��� ����� ���Խ��״�.
	// GetPay()�� ShowSalaryInfo()�� �����Կ��� �ش� Ŭ�������� ������ �̸��� ���·� �� �Լ��� �����Ͽ���.
	// �̸� �Լ� �������̵�(Function Overriding)�̶�� �Ѵ�.
	// �������̵� �� ���� Ŭ������ �Լ���, �������̵��� �� ���� Ŭ������ �Լ��� ��������.
	// ����, SalesWorker Ŭ���� ������ GetPay �Լ��� ȣ���ϸ�, SalesWorker Ŭ������ ���ǵ� GetPay �Լ��� ȣ��ȴ�.
	// ������ PermanentWorker::GetPay()�� �������̵� �� ���� Ŭ������ GetPay �Լ��� ȣ���ϴ� �����̴�.
};

class ForeignSalesWorker : public SalesWorker
{
private:
	const int riskLevel;
public:
	ForeignSalesWorker(const char *name, int money, double ratio, int risk) : SalesWorker(name, money, ratio), riskLevel(risk)
	{

	}
	int GetRiskPay() const
	{
		return (int)SalesWorker::GetPay() * (riskLevel / 100.0);
	}
	int GetPay() const
	{
		return (int)SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary : " << SalesWorker::GetPay() << "\n";
		cout << "risk pay: " << GetRiskPay() << "\n";
		cout << "sum : " << GetPay() << "\n" << "\n";
	}
};

int main(void)
{
	// ���� ���� �������� ����� ��Ʈ�� Ŭ���� ��ü ����
	EmployeeHandler handler;

	// �ؿ� ������ ���
	ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}