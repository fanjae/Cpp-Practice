#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjCnt; // static 변수를 public으로 선언함.
public:
	SoSimple()
	{
		simObjCnt++; 
	}
};
int SoSimple::simObjCnt = 0;

int main(void)
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << "\n"; // 클래스 이름을 이용해서 SimObjCnt에 접근이 가능하다.(static 멤버변수가 객체 내에 존재하지 않음)
	SoSimple sim1;
	SoSimple sim2;


	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << "\n";  
	cout << sim1.simObjCnt << "번째 SoSimple 객체 " << "\n";  // public이기 때문에 sim1,sim2를 이용해서 static 멤버변수에 접근이 가능하다.
	cout << sim2.simObjCnt << "번째 SoSimple 객체 " << "\n";

	return 0;
}