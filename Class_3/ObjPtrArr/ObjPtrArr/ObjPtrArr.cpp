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
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << "\n";
	}
	void SetPersonInfo(char *myname, int myage)
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
		cout << "called destructor!" << "\n";
	}
};
int main(void)
{
	Person *parr[3]; // 포인터 배열 선언, 객체 주소값 저장
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;
		parr[i] = new Person(namestr, age); // 객체 주소값 저장
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}