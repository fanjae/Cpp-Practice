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

class CCC : public BBB // 예외 클래스가 상속관계로 묶임에 따라 AAA 객체로 일종됨.
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
		ExceptionGeneator(3); // 반드시 예외가 발생하므로 주석처리 통한 확인필요
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
