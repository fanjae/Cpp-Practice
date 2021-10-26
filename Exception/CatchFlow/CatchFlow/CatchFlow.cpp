#include <iostream>
using namespace std;

class AAA
{
public:
	void ShowYou() {
		cout << "AAA exception!" << endl;
	}
};

class BBB : public AAA
{
public:
	void ShowYou()
	{
		cout << "BBB exception!" << endl;
	}
};

class CCC : public BBB // ���� Ŭ������ ��Ӱ���� ���ӿ� ���� AAA ��ü�� ������.
{
public:
	void ShowYou()
	{
		cout << "CCC exception!" << endl;
	}
};

void ExceptionGeneator(int expn) 
{
	if (expn == 1)
	{
		throw AAA();
	}
	else if (expn == 2)
	{
		throw BBB();
	}
	else
	{
		throw CCC();
	}
}

int main(void)
{
	try
	{
		ExceptionGeneator(3); // �ݵ�� ���ܰ� �߻��ϹǷ� �ּ�ó�� ���� Ȯ���ʿ�
		ExceptionGeneator(2);
		ExceptionGeneator(1);
	}
	catch (AAA& expn)
	{
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB& expn)
	{
		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (CCC& expn)
	{
		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}
	return 0;
}
