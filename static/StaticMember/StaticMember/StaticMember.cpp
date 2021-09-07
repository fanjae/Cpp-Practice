#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt; // SoSimple 객체 내에서 공유된다.
public:
	SoSimple()
	{
		simObjCnt++; // 멤버 변수처럼 접근이 가능하다. 단, 멤버변수는 아니다.
		cout << simObjCnt << "번째 SoSimple 객체" << "\n";
	}
};
int SoSimple::simObjCnt = 0; // static 변수는 클래스 외부에서 초기화를 진행한다. (객체가 할당될때 생성되는 변수가 아니기 때문이다.)

class SoComplex
{
private:
	static int cmxObjCnt; // SoComplex 객체 내에서 공유된다.
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << "\n";
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << "\n";
	}
};
int SoComplex::cmxObjCnt = 0; // static 변수는 클래스 외부에서 초기화를 진행한다. (객체가 할당될때 생성되는 변수가 아니기 때문이다.)

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();
	return 0;
}