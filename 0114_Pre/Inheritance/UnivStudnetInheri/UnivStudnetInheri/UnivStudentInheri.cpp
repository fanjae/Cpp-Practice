#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage, const char *myname) : age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << "\n";
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << "\n";
	}
};

class UnivStudent : public Person // Person Ŭ������ �����. (public�� �� ���Ĵ� ���� ���)
{
private:
	char major[50]; // ��������
public:
	UnivStudent(const char *myname, int myage,const char *mymajor) : Person(myage, myname)
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is " << major << "\n" << "\n";
	}
};

int main(void)
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
	return 0;
}
