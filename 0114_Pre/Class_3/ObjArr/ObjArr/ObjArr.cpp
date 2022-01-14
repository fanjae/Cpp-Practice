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
	Person() // �迭 ������ �ʿ��� ������
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << "\n";
	}
	void SetPersonInfo(char *myname, int myage) // ������ �ʱ�ȭ�� �������� ���ǵ� �Լ�
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << ", ";
		cout << "���� : " << age << "\n";
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

	/* �̸��� ���̸� �Է¹޾Ƽ� �ش� ��ü �ʱ�ȭ */
	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
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