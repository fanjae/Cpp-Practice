#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjCnt; // static ������ public���� ������.
public:
	SoSimple()
	{
		simObjCnt++; 
	}
};
int SoSimple::simObjCnt = 0;

int main(void)
{
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << "\n"; // Ŭ���� �̸��� �̿��ؼ� SimObjCnt�� ������ �����ϴ�.(static ��������� ��ü ���� �������� ����)
	SoSimple sim1;
	SoSimple sim2;


	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << "\n";  
	cout << sim1.simObjCnt << "��° SoSimple ��ü " << "\n";  // public�̱� ������ sim1,sim2�� �̿��ؼ� static ��������� ������ �����ϴ�.
	cout << sim2.simObjCnt << "��° SoSimple ��ü " << "\n";

	return 0;
}