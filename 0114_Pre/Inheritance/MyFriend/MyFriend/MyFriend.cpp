#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class MyFriendInfo
{
private:
	char *name;
	int age;
public:
	MyFriendInfo(const char *myname, int myage) : age(myage)
	{
		int name_len = strlen(myname) + 1;
		name = new char[name_len + 1];
		strcpy(name, myname);
	}
	void ShowMyFriendInfo()
	{
		cout << "�̸� : " << name << "\n";
		cout << "���� : " << age << "\n";
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char *addr;
	char *phone;
public:
	MyFriendDetailInfo(const char *myname, int myage, const char *myaddr, const char *myphone) : MyFriendInfo(myname, myage)
	{
		int addr_len = strlen(myaddr) + 1;
		int phone_len = strlen(myphone) + 1;

		addr = new char[addr_len + 1];
		phone = new char[phone_len + 1];

		strcpy(addr, myaddr);
		strcpy(phone, myphone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "�ּ� : " << addr << "\n";
		cout << "��ȭ : " << phone << "\n" << "\n";
	}
};

int main(void)
{
	MyFriendDetailInfo Kim1("�赿��", 12, "��⵵ ��õ��", "010-1234-1234");
	MyFriendDetailInfo Park1("�ڵ���", 21, "����Ư���� ���Ǳ�", "010-1234-1235");
	
	Kim1.ShowMyFriendDetailInfo();
	Park1.ShowMyFriendDetailInfo();
}