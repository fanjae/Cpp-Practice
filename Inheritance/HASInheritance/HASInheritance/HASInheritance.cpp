#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{

	}
	void Shot()
	{
		cout << "BBARNG!" << "\n";
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs;
public:
	Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff)
	{
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << "\n";
		handcuffs--;
	}
};

int main(void)
{
	Police pman(5, 3); // 총알 5, 수갑 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;

	// 권총을 소유하는 경찰을 표현한 형태
	// 상속 관계는 IS-A 관계 뿐 아니라, HAS-A 관계도 표현할 수 있다.
}