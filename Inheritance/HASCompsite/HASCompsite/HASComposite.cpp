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
		cout << "BBANG!" << "\n";
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun *pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0)
		{
			pistol = new Gun(bnum);
		}
		else
		{
			pistol = NULL;
		}
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << "\n";
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
		{
			cout << "Hut BANG!" << "\n";
		}
		else
		{
			pistol->Shot();
		}
	}
	~Police()
	{
		if (pistol != NULL)
		{
			delete pistol;
		}
	}
};

int main(void)
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3); // 권총을 소유하지 않은 경찰
	pman2.Shot();
	pman2.PutHandcuff();
	return 0;
}
