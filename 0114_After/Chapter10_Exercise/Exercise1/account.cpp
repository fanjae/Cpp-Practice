#include<iostream>
#include<cctype>
#include"account.h"

BankAccount::BankAccount(const char* client, const char* num, double bal)
{
	strcpy(name, client);
	strcpy(acctnum, num);
	balance = bal;
}
void BankAccount::show(void) const
{
	std::cout << "이름 : " << name << "\n";
	std::cout << "계좌 : " << acctnum << "\n";
	std::cout << "잔액 : " << balance << "\n";
}
void BankAccount::deposit(double cash)
{
	balance += cash;
}
void BankAccount::withdraw(double cash)
{
	if ((balance - cash) < 0)
	{
		std::cout << "출금할 금액이 잔액보다 많습니다.\n";
	}
	else
	{
		balance -= cash;
	}
}