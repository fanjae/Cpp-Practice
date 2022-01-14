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
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police & ref) : handcuffs(ref.handcuffs)
	{
		if (ref.pistol != NULL)
		{
			pistol = new Gun(*(ref.pistol));
		}
		else
		{
			pistol = NULL;
		}
	}
	Police& operator=(const Police& ref)
	{
		if (pistol != NULL)
		{
			delete pistol;
		}

		if (ref.pistol != NULL)
		{
			pistol = new Gun(*(ref.pistol)); // Gun의 복사생성자가 호출된다.
		}
		else
		{
			pistol = NULL;
		}

		handcuffs = ref.handcuffs;
		return *this;
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
			cout << "Hut BAANG!" << "\n";
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
	Police pman2 = pman1; // 복사생성자 호출

	pman2.PutHandcuff();
	pman2.Shot();

	Police pman3(2, 4);
	pman3 = pman1;
	pman3.PutHandcuff();
	pman3.Shot();
	return 0;
}

