#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class DepositException : public AccountException
	
{
private:
	int reqDep;
public:
	DepositException(int money) : reqDep(money)
	{

	}
	void ShowExceptionReason()
	{
		cout << "[예외 메시지 : " << reqDep << "는 입금불가]" << endl;
	}
};

class WithdrawException : public AccountException
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{
	}
	void ShowExceptionReason()
	{
		cout << "[예외 메시지 : 잔액 " << balance << ", 잔액부족]" << endl;
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
	void Deposit(int money) throw (AccountException)
		// 상속에 의하여 WithdrawException도 AccountException 객체로 간주된다.
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (AccountException)
		// WithdrawException도 AccountException 객체로 간주되어 이러한 선언이 가능함.
	{
		if (money > balance)
		{
			throw WithdrawException(balance);
		}
		balance -= money;
	}
	void ShowMoney()
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
	catch (AccountException &expn)
		// 실제 전달되는 예외객체는 DepositException과 WithdrawException이다.
		// 상속의 관계로둘이 묶여 있기 때문에 AccountException 형으로 선언할 수 있다.
	{
		expn.ShowExceptionReason();

	}
	myAcc.ShowMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMoney();
	return 0;
}
