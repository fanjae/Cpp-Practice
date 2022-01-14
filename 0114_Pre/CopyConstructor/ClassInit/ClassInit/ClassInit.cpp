#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{

	}
	SoSimple(SoSimple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "CAlled SoSimple(SoSimple &copy)" << "\n";
	}
	void ShowSimpleData()
	{
		cout << num1 << "\n";
		cout << num2 << "\n";
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << "\n";
	SoSimple sim2 = sim1; // SoSimple sim2(sim1); 으로 변환하여 15행에 정의된 생성자가 호출된다.
	//위와 같이 15행에 정의된 생성자를 복사 생성자(Copy constructor)라 한다.
	cout << "생성 및 초기화 직후" << "\n";
	sim2.ShowSimpleData();
	return 0;
}