#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n) { }
	void ShowData() {
		cout << num << endl;
	}

	Number* operator->() // 주소값을 반환하도록 -> 연산자를 오버로딩 하공 ㅣㅆ다.
	{
		return this;
	}
	Number& operator*() // 객체 자신을 참조의 형태로 반환하도록 * 연산자를 오버로딩.
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;
	num->ShowData(); // num.operator->() 으로 반환하는 것은 주소값이다.
	// 따라서, 이 문장은. num.operator->()->ShowData(); 로 '->' 연산자를 하나 더 추가 시켜서 해석한 것이다.
	(*num).ShowData();
	return 0;
}