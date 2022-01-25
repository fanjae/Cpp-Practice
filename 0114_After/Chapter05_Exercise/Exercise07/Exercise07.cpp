#include <iostream>

using namespace std;

struct Car
{
	char name[100];
	int years;
};

int main(void)
{
	int count;
	cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
	cin >> count;

	Car *data = new Car[count];
	for (int i = 0; i < count; i++)
	{
		cout << "자동차 #" << i + 1 << ":" << endl;
		cout << "제작업체: ";
		cin.get(); // 한 글자 읽어들임.
		cin.getline(data[i].name, 100);
		cout << "제작년도: ";
		cin >> data[i].years;
	}

	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";
	for (int i = 0; i < count; i++)
	{
		cout << data[i].years << "년형 " << data[i].name << endl;
	}
}