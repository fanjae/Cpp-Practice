#include <iostream>
const int strsize = 100;
// Benevolent Order of Programmers 회원 구조체

using namespace std;
struct bop
{
	char fullname[strsize];			// 실명
	char title[strsize];			// 직함
	char bopname[strsize];			// BOP 아이디
	int preference;					// 0 = fullname, 1 = title, 2 = bopname
};

void menu(void);

int main()
{
	menu();
	
	char ch;
	bop data[5] = {
	{"Wimp Macho", "CEO", "Dong",0},
	{"Raki Rhodes", "Junior Programmer", "Raki Rhodes",0},
	{"Celia Laiter", "MIPS", "Celia Laiter",1},
	{"Hopy Hipman", "Analyst Trainee", "Hopy Hipman",1},
	{"Pat Hand", "MIPS", "LOOPY"} };

	cout << "원하는 것을 선택하십시오: ";
	cin >> ch;
	while (ch != 'q')
	{
		if (ch == 'a')
		{
			for (int i = 0; i < 5; i++)
			{
				cout << data[i].fullname << endl;
			}
		}
		else if (ch == 'b')
		{
			for (int i = 0; i < 5; i++)
			{
				cout << data[i].title << endl;
			}
		}
		else if(ch == 'c')
		{
			for (int i = 0; i < 5; i++)
			{
				cout << data[i].bopname << endl;
			}
		}
		else if(ch == 'd')
		{
			for (int i = 0; i < 5; i++)
			{
				switch (data[i].preference)
				{
					case 0:
					{
						cout << data[i].fullname << endl;
						break;
					}
					case 1:
					{
						cout << data[i].title << endl;
						break;
					}
					case 2:
					{
						cout << data[i].bopname << endl;
						break;
					}
				}
			}
		}
		else if (ch == 'q')
		{
			cout << "프로그램을 종료합니다.\n";
			break;
		}
		cout << "원하는 것을 선택하십시오: ";
		cin >> ch;
	}
}

void menu(void)
{
	cout << "a. 실명으로 열람		b. 직함으로 열람\n";
	cout << "c. BOP 아이디로 열람		d. 회원이 지정한 것으로 열람\n";
	cout << "q. 종료\n";
}



