#include <iostream>
#include <string>

#pragma warning (disable:4996)
using namespace std;
const int NAME_LEN = 20;

// ���α׷� ������� ���� �޴�
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// �ſ���
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// ������ ����
enum { NORMAL = 1, CREDIT = 2 };


/* Class
Ŭ���� �̸� : Account
Ŭ���� ���� : Entity Ŭ����
Entity Ŭ����
- �������� ������ ���ϴ�.
- ���� �� ������ ���̽��� ����Ǵ� �����͸� ����.
- ���α׷��� ����� �ľ��ϴµ��� ������ ���� ���ϳ�, �������� ������ �ľ��ϴµ� ������ ��
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

Account::Account(int ID, int money, char *name) : accID(ID), balance(money) // Account ��ü ������
{
	acc_name = new char[strlen(name) + 1];
	strcpy(acc_name, name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance)
{
	acc_name = new char[strlen(ref.acc_name) + 1];
	strcpy(acc_name, ref.acc_name);
}
int Account::GetAccID() const // ������� ID ������ �Լ�
{
	return accID;
}

void Account::Deposit(int money) // �Ա�
{
	balance += money;
}

int Account::Withdraw(int money) // ���
{
	if (balance < money)
	{
		return 0;
	}
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const // ������� ��ü ���
{
	cout << "����ID : " << accID << "\n";
	cout << "�ܾ� : " << balance << "\n";
	cout << "�̸� : " << acc_name << "\n";
}

Account::~Account()
{
	delete[] acc_name;
}

/*
Ŭ���� �̸� : NormalAccount
Ŭ���� ���� : Entity Ŭ����
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
		Account::Deposit(money); // ����
		Account::Deposit(money * (interRate / 100.0));
	}
};

/*
Ŭ���� �̸� : HighCreditAccount
Ŭ���� ���� : Entity Ŭ����
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
		NormalAccount::Deposit(money); // ���ݰ� �����߰�
		Account::Deposit(money * (specialRate / 100.0)); // Ư�������߰�
	}
};
/* Class
Ŭ���� �̸� : AccountHandler
Ŭ���� ���� : ��Ʈ�� Ŭ����
Control Ŭ����
- ���α׷� ��ü�� ����� ����Ѵ�.
- ��Ʈ�� Ŭ������ ���� ��ü ��ɰ� �帧�� �Ǵ��� �����ϴ�.
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

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "���� : ";
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