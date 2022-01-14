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
		cout << "Called SoSimple(const SoSimple &copy)" << "\n";
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

SoSimple SimpleFuncObj(SoSimple ob) // 인자 전달 과정에서 복사 생성자 호출
{
	cout << "return 이전" << "\n";
	return ob; // 반환형이 참조형이 아님 따라서, ob 객체의 복사본이 만들어져서 반환된다.
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData(); // SimpleFuncObj에서 obj의 복사본인 객체가 보내짐에 따라서 obj의 멤버변수 값은 증가하지 않음.
	obj.ShowData();
	return 0;
}