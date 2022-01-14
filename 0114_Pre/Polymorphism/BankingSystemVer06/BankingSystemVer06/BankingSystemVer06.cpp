#include <iostream>
#include <string>

#pragma warning (disable:4996)
using namespace std;
const int NAME_LEN = 20;

// 프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };


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

/*
클래스 이름 : NormalAccount
클래스 유형 : Entity 클래스
*/

class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int ID, int money, char *name, int rate) : Account(ID, money, name), interRate(rate)
	{

	}
	virtual void Deposit(int money)
	{
		Account::Deposit(money); // 원금
		Account::Deposit(money * (interRate / 100.0));
	}
};

/*
클래스 이름 : HighCreditAccount
클래스 유형 : Entity 클래스
*/

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, char *name, int rate, int special) : NormalAccount(ID, money, name, rate), specialRate(special)
	{

	}

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); // 원금과 이자추가
		Account::Deposit(money * (specialRate / 100.0)); // 특별이자추가
	}
};
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
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
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
	int sel;
	cout << "[계좌종류선택]" << "\n";
	cout << "1.보통예금계좌 ";
	cout << "2.신용신뢰계좌 " << "\n";
	cout << "선택 : ";
	cin >> sel;

	if (sel == NORMAL)
	{
		MakeNormalAccount();
	}
	else
	{
		MakeCreditAccount();
	}
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌 개설]" << "\n";
	cout << "계좌ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
	cout << "이자율 : ";
	cin >> interRate;
	cout << "\n";

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설]" << "\n";
	cout << "계좌 ID : ";
	cin >> id;
	cout << "이 름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
	cout << "이자율 : ";
	cin >> interRate;
	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> creditLevel;
	cout << "\n";

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
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