#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

class Employee // 고용인을 의미하는 Employee 클래스 추가
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

class PermanentWorker : public Employee // Employee 클래스를 상속하도록 변경
{
private:
	int salary;			// 매달 지불해야 하는 급여액
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
	Employee *empList[50]; // 기존 PermanentWorker 객체에서 Employee 객체로 변경되었다. PermanentWorker 객체 역시 Employee 객체의 일종이므로 저장이 가능하다.
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{
	}
	void AddEmployee(Employee *emp) // Employee 객체의 주소값을 전달해야 한다. 따라서, Employee 클래스를 상속하는 PermanentWorker 객체 주소값 전달도 가능하다.
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		/* Compile Error로 인한 주석처리
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/* Compile Error로 인한 주석처리
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
	// 직원 관리 목적으로 설계된 컨트롤 클래스 객체 생성
	EmployeeHandler handler;


	// 직원 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000)); 
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번 달에 지불해야 할 급여 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;

}