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
		cout << "[���� �޽��� : " << reqDep << "�� �ԱݺҰ�]" << endl;
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
		cout << "[���� �޽��� : �ܾ� " << balance << ", �ܾ׺���]" << endl;
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
		// ��ӿ� ���Ͽ� WithdrawException�� AccountException ��ü�� ���ֵȴ�.
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (AccountException)
		// WithdrawException�� AccountException ��ü�� ���ֵǾ� �̷��� ������ ������.
	{
		if (money > balance)
		{
			throw WithdrawException(balance);
		}
		balance -= money;
	}
	void ShowMoney()
	{
		cout << "�ܰ� : " << balance << endl << endl;
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
		// ���� ���޵Ǵ� ���ܰ�ü�� DepositException�� WithdrawException�̴�.
		// ����� ����ε��� ���� �ֱ� ������ AccountException ������ ������ �� �ִ�.
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