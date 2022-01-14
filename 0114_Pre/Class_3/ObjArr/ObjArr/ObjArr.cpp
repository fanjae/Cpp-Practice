#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class Person
{
private:
	char *name;
	int age;
public:
	Person(char *myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person() // 배열 생성시 필요한 생성자
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << "\n";
	}
	void SetPersonInfo(char *myname, int myage) // 데이터 초기화를 목적으로 정의된 함수
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << ", ";
		cout << "나이 : " << age << "\n";
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor! " << "\n";
	}
};

int main(void)
{
	Person parr[3];
	char namestr[100];
	char *strptr;
	int age;
	int len;

	/* 이름과 나이를 입력받아서 해당 객체 초기화 */
	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}
	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	return 0;
}