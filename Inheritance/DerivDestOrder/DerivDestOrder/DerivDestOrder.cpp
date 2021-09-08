#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase() : " << baseNum << "\n";
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << "\n";
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << "\n";
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << "\n";
	}
};

int main(void)
{
	SoDerived drv1(15);
	SoDerived drv2(27);

	// 유도 클래스의 객체가 소멸될때는 유도 클래스의 소멸자가 먼저 실행되고 난 다음에
	// 기초 클래스의 소멸자가 실행된다.
	// 스택에 생성된 객체의 소멸 순서는 생성순서와 반대이다.
	return 0;
}