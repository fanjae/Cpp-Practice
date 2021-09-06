#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << "\n";
	}
	void ShowData() const
	{
		cout << "num : " << num << "\n";
	}
};

void SimpleFunctionObj(SoSimple ob)
{
	ob.ShowData();
}

int main(void)
{
	SoSimple obj(7);
	cout << "함수호출 전" << "\n";
	SimpleFunctionObj(obj); // 함수 호출 후 인자를 전달하는 과정에서 복사 생성자의 호출을 확인 가능
	cout << "함수호출 후" << "\n";
	return 0;
}
