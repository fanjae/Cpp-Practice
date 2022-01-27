#include <iostream>
using namespace std;
void menu(void);
void wrong(void);
int main()
{
	char ch;
	menu();
	cin >> ch;
	while(ch != 'q')
	{
		switch (ch)
		{
			case 'c':
				cout << "이 카메라는 멋집니다.";
				break;
			case 'p':
				cout << "이 피아니스트는 훌륭합니다.";
				break;
			case 't':
				cout << "이 나무는 큽니다.";
				break;
			case 'g':
				cout << "이 게임은 재미있습니다.";
				break;
			default:
				wrong();
				cin >> ch;
				continue;
		}
		break;
	}
}
void menu(void)
{
	cout << "다음 선택 사항 중에서 하나를 선택하십시오.  (끝내려면 q)\n";
	cout << "c) camera	p) pianist\n";
	cout << "t) tree		g) game\n";
}
void wrong(void)
{
	cout << "c, p, t, g 중에서 하나를 선택하십시오. (끝내려면 q) : ";
}