#include <iostream>
#include <cstring>

#pragma warning (disable:4996)

using namespace std;

/* ���� ������ ���� �ʴ� ���α׷�
���� ���簡 �ʿ��� ������ ���̴� �����̴�. */
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
		cout << "�̸� : " << name << "\n";
		cout << "���� : " << age << "\n";
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
	Person man2 = man1; // ���� ����
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	// �� ���� ����� ���Ͽ�, �ϳ��� ���ڿ��� �� ���� ��ü�� ���ÿ� ������.
	// ���� man2�� ���� �Ҹ�ȴٸ�, name�� �Ҹ�ʿ� ����, ������ �߻��Ѵ�.

	return 0;
}