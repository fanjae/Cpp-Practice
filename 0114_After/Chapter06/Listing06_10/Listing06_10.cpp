#include <iostream>
using namespace std;
void showmenu();
void report();
void comfort();
int main()
{
	showmenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1: cout << "\a\n";
			break;
		case 2: report();
			break;
		case 3: cout << "사장님은 오늘 회사에 계셨습니다.\n";
			break;
		case 4: comfort();
			break;
		default: cout << "그것은 선택할 수 없습니다.\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}

void showmenu()
{
	cout << "1, 2, 3, 4, 5번 중에서 하나를 선택하십시오:\n"
			"1) 경고음			2) 보고서\n"
			"3) 알리바이			4) 격려사\n"
			"5) 종료\n";
}
void report()
{
	cout << "이번 분기는 경영 실적이 아주 좋습니다.\n"
		"판매량은 120% 늘어났고, 비용은 35% 줄었습니다.\n";
}

void comfort()
{
	cout << "사원들은 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n"
			"이사회도 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n";
}

/* break 구문을 이용하여 switch 구문의 특정 부분만 수행하도록 제한하고 있다.
break 구문이 제거된 상태에서 2가 입력된다면, case 2, case 3, case 4, default에 있는
모든 구문을 차례대로 수행한다. */