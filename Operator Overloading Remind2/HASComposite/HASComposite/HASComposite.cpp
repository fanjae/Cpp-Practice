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
	Police(const Police& ref) : handcuffs(ref.handcuffs)
	{
		if (ref.pistol != NULL)
		{
			pistol = new Gun(*(ref.pistol)); // Gun의 복사 생성자.
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
			pistol = new Gun(*(ref.pistol));
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
	Police pman2 = pman1;
	pman2.Shot();
	pman2.PutHandcuff();

	Police pman3(2, 4);
	pman3 = pman1;
	pman3.PutHandcuff();
	pman3.Shot();
	return 0;

	// 일반적인 상황에서는 앞선 HAS-A 예제2보다 이 예제가 훨씬더 낫다.
	// 상속은 IS-A 관계의 표현에 매우 적절하나,
	// HAS-A 관계의 표현에도 사용될 수 있으나, 이는 프로그램의 변경에 많은 제약을 가져다 줄 수 있다.
}