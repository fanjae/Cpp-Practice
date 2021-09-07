#include <iostream>
#include <string>

#pragma warning (disable:4996)
using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);		// �޴����
void MakeAccount(void);		// ���°����� ���� �Լ�
void DepositMoney(void);	// �Ա�
void WithdrawMoney(void);	// ���
void ShowAllAccInfo(void);	// �ܾ� ��ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;
	int balance;
	char *acc_name;
public:
	Account(int ID, int money, char *name) : accID(ID), balance(money) // Account ��ü ������
	{
		acc_name = new char[strlen(name) + 1];
		strcpy(acc_name, name);
	}

	Account(const Account &ref) : accID(ref.accID), balance(ref.balance)
	{
		acc_name = new char[strlen(ref.acc_name) + 1];
		strcpy(acc_name, ref.acc_name);
	}
	int GetAccID() const // ������� ID ������ �Լ�
	{
		return accID;
	}

	void Deposit(int money) // �Ա�
	{
		balance += money;
	}

	int Withdraw(int money) // ���
	{
		if (balance < money)
		{
			return 0;
		}
		balance -= money;
		return money;
	}

	void ShowAccInfo() const // ������� ��ü ���
	{
		cout << "����ID : " << accID << "\n";
		cout << "�ܾ� : " << balance << "\n";
		cout << "�̸� : " << acc_name << "\n";
	}

	~Account()
	{
		delete[]acc_name;
	}
};

Account *accArr[100];
int accNum = 0;

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "���� : ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << "\n";
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu------" << "\n";
	cout << "1. ���°��� " << "\n";
	cout << "2. �Ա� " << "\n";
	cout << "3. ��� " << "\n";
	cout << "4. �������� ��ü ��� " << "\n";
	cout << "5. ���α׷� ���� " << "\n";
}

void MakeAccount(void)
{
	int temp_accID;
	int temp_balance;
	char temp_name[NAME_LEN];

	cout << "[���°輳]" << "\n";
	cout << "����ID : ";
	cin >> temp_accID;
	cout << "�̸� : ";
	cin >> temp_name;
	cout << "�Աݾ� : ";
	cin >> temp_balance;

	accArr[accNum] = new Account(temp_accID, temp_balance, temp_name);

	cout << "���� �Ϸ� " << "\n" << "\n";
	accNum++;
}

void DepositMoney(void)
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

void WithdrawMoney(void)
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

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << "\n";
	}
}