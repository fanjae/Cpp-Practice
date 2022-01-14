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
	cout << "1. ���°��� " << "\n";
	cout << "2. �Ա� " << "\n";
	cout << "3. ��� " << "\n";
	cout << "4. �������� ��ü ��� " << "\n";
	cout << "5. ���α׷� ���� " << "\n";
}

void AccountHandler::MakeAccount(void)
{
	int sel;
	cout << "[������������]" << "\n";
	cout << "1.���뿹�ݰ��� ";
	cout << "2.�ſ�ŷڰ��� " << "\n";
	cout << "���� : ";
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

	cout << "[���뿹�ݰ��� ����]" << "\n";
	cout << "����ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> balance;
	cout << "������ : ";
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

	cout << "[�ſ�ŷڰ��� ����]" << "\n";
	cout << "���� ID : ";
	cin >> id;
	cout << "�� �� : ";
	cin >> name;
	cout << "�Աݾ� : ";
	cin >> balance;
	cout << "������ : ";
	cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
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

	cout << "[��   ��] " << "\n";
	cout << "����ID : ";
	cin >> ID;
	cout << "�Աݾ� : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << "\n" << "\n";
			return;
		}
	}
	cout << "�ش� ID�� �������� �ʽ��ϴ�. " << "\n" << "\n";
}

void  AccountHandler::WithdrawMoney(void)
{
	int ID;
	int money;

	cout << "[��   ��] " << "\n";
	cout << "����ID : ";
	cin >> ID;
	cout << "��ݾ� : ";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ��� �����մϴ�." << "\n" << "\n";
				return;

				return;
			}
			else
			{
				cout << "��ݿϷ�" << "\n" << "\n";
				return;
			}
		}
	}
	cout << "�ش� ID�� �������� �ʽ��ϴ�. " << "\n" << "\n";
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
