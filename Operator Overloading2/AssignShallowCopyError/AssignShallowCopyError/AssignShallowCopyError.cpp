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
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << "\n";
		cout << "나이 : " << age << "\n";
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << "\n";
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1; // 대입 연산자가 호출된다. Person 클래스에서는 대입 연산자가 정의되어있지 않아서
	// 디폴트 대입 연산자가 호출된다.
	// 이 경우, 하나의 문자열을 두 객체가 동시에 참조하는 상황이 벌어지게 된다.


	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}