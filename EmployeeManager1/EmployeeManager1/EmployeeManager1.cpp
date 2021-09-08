#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;
class PermanentWorker
{
private:
	char name[100];
	int salary;			// 매달 지불해야 하는 급여액
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

	/*
	소프트웨어 설계에서 요구사항의 변경에 대응하는 프로그램의 유연성이나
	기능의 추가에 따른 프로그램의 확정성이 필요하다.

	위의 예제는 추가적인 확정성을 위해서 클래스의 추가로 인한 변경을 최소화하기 어렵다.
	따라서, 이런 부분에 대한 조치가 필요하다.
	*/
}
