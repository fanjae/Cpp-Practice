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
		cout << "이름 : " << name << "\n";
		cout << "나이 : " << age << "\n";
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
		cout << "주소 : " << addr << "\n";
		cout << "전화 : " << phone << "\n" << "\n";
	}
};

int main(void)
{
	MyFriendDetailInfo Kim1("김동욱", 12, "경기도 포천시", "010-1234-1234");
	MyFriendDetailInfo Park1("박동준", 21, "서울특별시 관악구", "010-1234-1235");
	
	Kim1.ShowMyFriendDetailInfo();
	Park1.ShowMyFriendDetailInfo();
}