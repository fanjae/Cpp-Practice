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
	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num : " << num << "\n";
	}
};

int main(void)
{
	const SoSimple obj(7); // 객체의 데이터 변경을 허용치 않는다.
	// obj.AddNum(20); const 함수가 아니므로 호출이 불가능하다.
	obj.ShowData(); // const 함수이기 때문에 const 객체를 대상으로 호출이 가능하다.
	return 0;
}