#include <iostream>
#include <string>

#pragma warning (disable:4996)
using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);		// 메뉴출력
void MakeAccount(void);		// 계좌개설을 위한 함수
void DepositMoney(void);	// 입금
void WithdrawMoney(void);	// 출금
void ShowAllAccInfo(void);	// 잔액 조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;
	int balance;
	char name[NAME_LEN];
} Account;

Account accArr[100];		// Account 저장을 위한 배열
int accNum = 0;				// 저장된 Account 수

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택 : ";
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
	cout << "1. 계좌개설 " << "\n";
	cout << "2. 입금 " << "\n";
	cout << "3. 출금 " << "\n";
	cout << "4. 계좌정보 전체 출력 " << "\n";
	cout << "5. 프로그램 종료 " << "\n";
}

void MakeAccount(void)
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

	accArr[accNum].accID = temp_accID;
	accArr[accNum].balance = temp_balance;
	strcpy(accArr[accNum].name, temp_name);

	cout << "개설 완료 " << "\n" << "\n";
	accNum++;
}

void DepositMoney(void)
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
		if (accArr[i].accID == ID)
		{
			accArr[i].balance += money;
			cout << "입금완료" << "\n" << "\n";
			return ;
		}
	}
	cout << "해당 ID가 존재하지 않습니다. " << "\n" << "\n";
}

void WithdrawMoney(void)
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
		if (accArr[i].accID == ID)
		{
			if (accArr[i].balance >= money)
			{
				accArr[i].balance -= money;
				cout << "출금완료" << "\n" << "\n";
				return;
			}
			else
			{
				cout << "잔액이 부족합니다." << "\n" << "\n";
				return;
			}
		}
	}
	cout << "해당 ID가 존재하지 않습니다. " << "\n" << "\n";
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID : " << accArr[i].accID << "\n";
		cout << "이름 : " << accArr[i].name << "\n";
		cout << "잔액 : " << accArr[i].balance << "\n" << "\n";
	}
}
			
