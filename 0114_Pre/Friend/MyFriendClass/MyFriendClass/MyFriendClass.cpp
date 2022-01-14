#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class Girl; // Girl이 클래스 이름임을 사전에 알림

class Boy
{
private:
	int height;
	friend class Girl; // private의 영역에도 Friend 선언이 가능함.
public:
	Boy(int len) : height(len)
	{

	}
	void ShowYourFriendInfo(Girl &frn); // Girl이 나올 수 있는 이유는 사전에 Class임을 알렸기 때문이다.
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
	cout << "Her phone number : " << frn.phNum << "\n"; // Friend class이므로, 위와 같이 Boy 클래스에서 직접적으로 접근 가능함.
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout << "His height : " << frn.height << "\n"; // Friend class이므로, 위와 같이 Girl 클래스에서 직접적으로 접근 가능함
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl); 
	girl.ShowYourFriendInfo(boy);
	return 0;
}