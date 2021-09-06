#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj : " << num << "\n";
	}
	~Temporary()
	{
		cout << "destroy obj : " << num << "\n";
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << "\n";
	}
};

int main(void)
{
	Temporary(100); // 임시 객체 생성 방법
	cout << "********* after make!" << "\n" << "\n";
	

	Temporary(200).ShowTempInfo(); // 임시 객체 생성 후 특정 함수 호출, 객체가 생성 및 반환되면 반환 위치에 객체를 참조할 수 있는 참조값이 반환된다.
	cout << "********* after make!" << "\n" << "\n";

	const Temporary &ref = Temporary(300); // 참조자를 이용하여 임시객체를 참조함. 이때의 임시객체는 바로 소멸되지 않는다.
	cout << "********* after make!" << "\n" << "\n";
	return 0;
}