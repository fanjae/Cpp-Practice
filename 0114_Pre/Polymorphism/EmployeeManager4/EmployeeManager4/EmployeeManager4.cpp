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
	virtual int GetPay() const = 0;				// 위와 같이 정의되면 순수 가상 함수이다.
	virtual void ShowSalaryInfo() const = 0;	// 위와 같이 정의되면 순수 가상 함수이다.
	/* 순수 가상 함수란 함수의 몸체가 정의되지 않은 함수이다.
	순수 가상 함수를 지닌, 완전하지 않은 클래스가 되기 때문에,
	이 객체를 생성하려 들면 컴파일 에러가 발생한다. */
};

class PermanentWorker : public Employee // Employee 클래스를 상속하도록 변경
{
private:
	int salary;			// 매달 지불해야 하는 급여액
public:
	PermanentWorker(const char *name, int money) : Employee(name), salary(money)
	{

	}
	int GetPay() const // Employee 클래스에 GetPay와 ShowSalaryInfo 함수를 추가로 정의하고 가상함수로 선언함.
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

class TemporaryWorker : public Employee // 임시직
{
private:
	int workTime;		// 이 달에 일한 시간의 합계
	int payPerHour;		// 시간당 급여
public:
	TemporaryWorker(const char *name, int pay) : Employee(name), workTime(0), payPerHour(pay)
	{

	}
	void AddWorkTime(int time)	// 일한 시간의 추가
	{
		workTime += time;
	}
	virtual int GetPay() const 	// 이 달의 급여
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
	int salesResult;		// 월 판매실적
	double bonusRatio;		// 상여금 비율
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
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio); // PermanentWorker의 GetPay 함수 호출
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary : " << GetPay() << "\n" << "\n";
	}
	// PermanentWorker를 상속함으로써 기본 급여와 관련된 부분을 멤버로 포함시켰다.
	// GetPay()와 ShowSalaryInfo()가 존재함에도 해당 클래스에서 동일한 이름과 형태로 두 함수를 정의하였다.
	// 이를 함수 오버라이딩(Function Overriding)이라고 한다.
	// 오버라이딩 된 기초 클래스의 함수는, 오버라이딩을 한 유도 클래스의 함수에 가려진다.
	// 따라서, SalesWorker 클래스 내에서 GetPay 함수를 호출하면, SalesWorker 클래스에 정의된 GetPay 함수가 호출된다.
	// 위에서 PermanentWorker::GetPay()는 오버라이딩 된 기초 클래스의 GetPay 함수를 호출하는 구문이다.
};
int main(void)
{
	// 직원 관리 목적으로 설계된 컨트롤 클래스 객체 생성
	EmployeeHandler handler;

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 임시직 등록
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5); // 5시간 일한 결과 등록
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달 지불해야 할 급여의 총합
	handler.ShowTotalSalary();

	// Employee *emp = new Employee("Lee Dong Sook"); // 순수 가상함수 추가에 따른 Compile Error
	// 문법적으로는 문제가 없다.
	// 하지만 Employee 클래스는 기초 클래스로서만 의미를 가질뿐 객체의 생성을 목적으로 정의된 클래스가 아니다.
	// 클래스 중에서는 객체생성 목적으로 정의되지 않는 클래스도 존재한다.


	return 0;

}