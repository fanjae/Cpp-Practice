#include <iostream>
#include <cstring>
using namespace std;

#pragma warning (disable:4996)
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
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1; // Person 클래스에는 별도 대입 연산자가 정의되어있지 않다.
	// 따라서, 디폴트 대입 연산자가 호출된다.

	// 디폴트 대입 연산자만 사용할 경우,
	// 멤버 대 멤버 복사가 이뤄진다. 따라서 별도로 연산자 오버로딩이 필요하다.

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}