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
	/* 일반적으로는 복사 생성자가 자동으로 삽입된다. 
	*/
	explicit SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "CAlled SoSimple(SoSimple &copy)" << "\n";
	}
	void ShowSimpleData() const
	{
		cout << num1 << "\n";
		cout << num2 << "\n";
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << "\n";
	SoSimple sim2(sim1); // explicit를 사용하면 SoSimple sim2=sim1을 묵시적으로 변환하는 것을 허용치 않는다.
	// SoSimple sim2 = sim1; (Compile Error)
	cout << "생성 및 초기화 직후" << "\n";
	sim2.ShowSimpleData();
	return 0;
}