#include <iostream>
#include "account.h"

int main()
{
	BankAccount test = { "test name","test account num",1000.0 };
	test.show();
	test.deposit(250);
	test.show();
	test.withdraw(1500);
	test.withdraw(300);
	test.withdraw(200);
	test.show();


	return 0;
}
