#include <iostream>
#include <string>

#pragma warning (disable:4996)
using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/* Class
클래스 이름 : Account
클래스 유형 : Entity 클래스
Entity 클래스
- 데이터적 성격이 강하다.
- 파일 및 데이터 베이스에 저장되는 데이터를 소유.
- 프로그램의 기능을 파악하는데는 도움을 주지 못하나, 데이터의 종류를 파악하는데 도움이 됨
*/ 
class Account
{
private:
	int accID;
	int balance;
	char *acc_name;
public:
	Account(int ID, int money, char *name);
	Account(const Account &ref);
	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account(int ID, int money, char *name) : accID(ID), balance(money) // Account 객체 생성자
{
	acc_name = new char[strlen(name) + 1];
	strcpy(acc_name, name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance)
{
	acc_name = new char[strlen(ref.acc_name) + 1];
	strcpy(acc_name, ref.acc_name);
}
int Account::GetAccID() const // 멤버변수 ID 엑세스 함수
{
	return accID;
}

void Account::Deposit(int money) // 입금
{
	balance += money;
}

int Account::Withdraw(int money) // 출금
{
	if (balance < money)
	{
		return 0;
	}
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const // 멤버변수 전체 출력
{
	cout << "계좌ID : " << accID << "\n";
	cout << "잔액 : " << balance << "\n";
	cout << "이름 : " << acc_name << "\n";
}

Account::~Account()
{
	delete[] acc_name;
}


/* Class
클래스 이름 : AccountHandler
클래스 유형 : 컨트롤 클래스
Control 클래스
- 프로그램 전체의 기능을 담당한다.
- 컨트롤 클래스를 보면 전체 기능과 흐름의 판단이 가능하다.
*/ 

class AccountHandler
{
private:
	Account *accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};


AccountHandler::AccountHandler() : accNum(0)
{

}

void AccountHandler::ShowMenu(void) const 
{
	cout << "-----Menu------" << "\n";
	cout << "1. 계좌개설 " << "\n";
	cout << "2. 입금 " << "\n";
	cout << "3. 출금 " << "\n";
	cout << "4. 계좌정보 전체 출력 " << "\n";
	cout << "5. 프로그램 종료 " << "\n";
}

void AccountHandler::MakeAccount(void)
{
	int temp_accID;
	int temp_balance;
	char temp_name[NAME_LEN];

	cout << "[계좌계설]" << "\n";
	cout << "계좌ID : ";
	cin >> temp_accID;
	cout << "이름 : ";
	cin >> temp_name;
	cout << "입금액 : ";
	cin >> temp_balance;

	accArr[accNum] = new Account(temp_accID, temp_balance, temp_name);

	cout << "개설 완료 " << "\n" << "\n";
	accNum++;
}

void  AccountHandler::DepositMoney(void)
{
	int ID;
	int money;

	cout << "[입   금] " << "\n";
	cout << "계좌ID : ";
	cin >> ID;
	cout << "입금액 : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << "\n" << "\n";
			return;
		}
	}
	cout << "해당 ID가 존재하지 않습니다. " << "\n" << "\n";
}

void  AccountHandler::WithdrawMoney(void)
{
	int ID;
	int money;

	cout << "[출   금] " << "\n";
	cout << "계좌ID : ";
	cin >> ID;
	cout << "출금액 : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액이 부족합니다." << "\n" << "\n";
				return;

				return;
			}
			else
			{
				cout << "출금완료" << "\n" << "\n";
				return;
			}
		}
	}
	cout << "해당 ID가 존재하지 않습니다. " << "\n" << "\n";
}

void  AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << "\n";
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << "\n";
		}
	}
	return 0;
}