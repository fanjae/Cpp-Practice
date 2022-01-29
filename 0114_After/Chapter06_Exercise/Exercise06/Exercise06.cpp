#include <iostream>
using namespace std;

const int str_Size = 100;
struct Society
{
	char name[str_Size];
	double dollar;
};

int main()
{
	Society data[105];
	int count;

	cout << "기부금을 낼 사람의 수를 입력하세요 : ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cout << "기부자의 이름을 입력하세요 : ";
		cin.get();
		cin.getline(data[i].name, str_Size);
		cout << "기부액을 입력하세요 : ";
		cin >> data[i].dollar;
	}

	if (count == 0)
	{
		cout << "기부자가 없습니다.\n";
	}
	else
	{
		cout << "==고액 기부자==\n";
		for (int i = 0; i < count; i++)
		{
			if (data[i].dollar >= 100000)
			{
				cout << "이름 : " << data[i].name;
				cout << " 기부액 : " << data[i].dollar;
				cout << "\n";
			}
		}

		cout << "==소액 기부자==\n";
		for (int i = 0; i < count; i++)
		{
			if (data[i].dollar < 100000)
			{
				cout << "이름 : " << data[i].name;
				cout << " 기부액 : " << data[i].dollar;
				cout << "\n";
			}
		}
	}

}