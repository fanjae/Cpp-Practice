#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class Girl; // Girl�� Ŭ���� �̸����� ������ �˸�

class Boy
{
private:
	int height;
	friend class Girl; // private�� �������� Friend ������ ������.
public:
	Boy(int len) : height(len)
	{

	}
	void ShowYourFriendInfo(Girl &frn); // Girl�� ���� �� �ִ� ������ ������ Class���� �˷ȱ� �����̴�.
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char *num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn) // Friend 
{
	cout << "Her phone number : " << frn.phNum << "\n"; // Friend class�̹Ƿ�, ���� ���� Boy Ŭ�������� ���������� ���� ������.
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout << "His height : " << frn.height << "\n"; // Friend class�̹Ƿ�, ���� ���� Girl Ŭ�������� ���������� ���� ������
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl); 
	girl.ShowYourFriendInfo(boy);
	return 0;
}