#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;


class DepositException // 예외 클래스이다. 입금 과정에서 발생할 수 있는 예외 상황을 알기 위해서 정의된 클래스
{
private:
	int reqDep;
public:
	DepositException(int money) : reqDep(money) 
	{
	}
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}
};

class WithdrawException  // 예외 클래스이다
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{
	}
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액 " << balance << ", 잔액부족]" << endl;
	}
};

class Account
{
private:
	char accNum[50];
	int balance;
public:
	Account(const char *acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (DepositException)
	{
		if (money < 0)
		{
			DepositException expn(money); // WithdrawException 도 예외 클래스이다. 
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (WithdrawException)
	{
		if (money > balance)
		{
			throw WithdrawException(balance); // 이와 같이 예외객체를 전달한다.
			// 예외객체는 C++의 예외처리 매커니즘에 의해 처리되므로, 이를 직접 참조할 필요가 없다.
		}
		balance -= money;
	}
	void ShowMyMoney()
	{
		cout << "잔고 : " << balance << endl << endl;
	}
};

int main(void)
{
	Account myAcc("56789-827120", 5000);
	
	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (DepositException &expn) // 참조자를 선언한 예외객체의 전달
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (WithdrawException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	return 0;
}
