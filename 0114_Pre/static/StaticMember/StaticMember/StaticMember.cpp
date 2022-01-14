#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt; // SoSimple ��ü ������ �����ȴ�.
public:
	SoSimple()
	{
		simObjCnt++; // ��� ����ó�� ������ �����ϴ�. ��, ��������� �ƴϴ�.
		cout << simObjCnt << "��° SoSimple ��ü" << "\n";
	}
};
int SoSimple::simObjCnt = 0; // static ������ Ŭ���� �ܺο��� �ʱ�ȭ�� �����Ѵ�. (��ü�� �Ҵ�ɶ� �����Ǵ� ������ �ƴϱ� �����̴�.)

class SoComplex
{
private:
	static int cmxObjCnt; // SoComplex ��ü ������ �����ȴ�.
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << "\n";
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << "\n";
	}
};
int SoComplex::cmxObjCnt = 0; // static ������ Ŭ���� �ܺο��� �ʱ�ȭ�� �����Ѵ�. (��ü�� �Ҵ�ɶ� �����Ǵ� ������ �ƴϱ� �����̴�.)

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();
	return 0;
}