#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << "\n";
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << "\n";
	}
	void ShowBaseData()
	{
		cout << baseNum << "\n";
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30) // 본 생성자에서는 기초 클래스에 대한 생성이 존재하지 않음을 확인할 수 있다. 이는 32행도 동일하다.
	{
		cout << "SoDerived()" << "\n";
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived(int n)" << "\n";
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) // 본 생성자만, 기초 클래스의 생성자 호출을 명시한다.
	{
		cout << "SoDerived(int n1, int n2)" << "\n";
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << "\n";
	}
};

int main(void)
{
	cout << "case1..... " << "\n"; // 실행하면 유도 클래스의 객체생성 과정에서 생성자가 두번 생성된다. (기초 생성자 및 유도 클래스 생성자)
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "---------------------" << "\n";
	cout << "case2..... " << "\n";
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "---------------------" << "\n";
	cout << "case3..... " << "\n";
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	return 0;
}