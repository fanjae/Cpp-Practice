//account.h
#ifndef account_H_
#define account_H_

class BankAccount
{
private:
	char name[40];
	char acctnum[25];
	double balance;
public:
	BankAccount(const char* client, const char* num, double bal = 0.0);
	void show(void) const;
	void deposit(double cash);
	void withdraw(double cash);
};
#endif