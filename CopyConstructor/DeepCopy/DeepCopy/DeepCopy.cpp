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
	Person(const char *myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person &copy) : age(copy.age) // 객체별로 각각의 문자열을 참조할 수 있도록 깊은 복사를 진행
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << "\n";
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
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}
