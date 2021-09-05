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

typedef struct
{
	int accID;
	int balance;
	char name[NAME_LEN];
} Account;

Account accArr[100];		// Account ������ ���� �迭
int accNum = 0;				// ����� Account ��

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

	accArr[accNum].accID = temp_accID;
	accArr[accNum].balance = temp_balance;
	strcpy(accArr[accNum].name, temp_name);

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
		if (accArr[i].accID == ID)
		{
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << "\n" << "\n";
			return ;
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
		if (accArr[i].accID == ID)
		{
			if (accArr[i].balance >= money)
			{
				accArr[i].balance -= money;
				cout << "��ݿϷ�" << "\n" << "\n";
				return;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�." << "\n" << "\n";
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
		cout << "����ID : " << accArr[i].accID << "\n";
		cout << "�̸� : " << accArr[i].name << "\n";
		cout << "�ܾ� : " << accArr[i].balance << "\n" << "\n";
	}
}
			
