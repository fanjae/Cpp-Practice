#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const
	{
		cout << "콧물이 싹~ 납니다. " << "\n";
	}
};
class SneezeCap
{
public:
	void Take() const
	{
		cout << "재채기가 멎습니다. " << "\n";
	}
};

class SnuffleCap
{
public:
	void Take() const
	{
		cout << "코가 뻥 뚫립니다." << "\n";
	}
};

class CONTAC600
{
	/* 관련있는 변수와 함수를 하나의 클래스 안에 묶어두어 캡슐화를 진행한다.
	유의할 점은 캡슐화의 범위를 결정할 때 신중하게 캡슐화를 진행해야 한다. */
	private:
		SinivelCap sin;
		SneezeCap sne;
		SnuffleCap snu;

	public:
		void Take() const
		{
			sin.Take();
			sne.Take();
			snu.Take();
		}
};

class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600 &cap) const
	{
		cap.Take();
	}
};

int main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}
