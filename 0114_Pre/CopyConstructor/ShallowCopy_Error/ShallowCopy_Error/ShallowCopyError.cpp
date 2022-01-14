#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

/* 정상 실행이 되지 않는 프로그램
깊은 복사가 필요한 이유를 보이는 예제이다. */
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
		delete[]name;
		cout << "called destrcutor!" << "\n";
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1; // 얕은 복사
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	// 현 복사 방법에 의하여, 하나의 문자열을 두 개의 객체가 동시에 참조함.
	// 만약 man2가 먼저 소멸된다면, name이 소멸됨에 따라서, 문제가 발생한다.

	return 0;
}