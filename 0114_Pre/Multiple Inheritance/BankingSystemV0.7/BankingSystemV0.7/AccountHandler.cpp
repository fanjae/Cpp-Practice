#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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
