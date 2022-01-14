#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num= " << num << ", ";
		cout << "address= " << this << endl; 
	}
	void ShowSimpleData() const
	{
		cout << num << "\n";
	}
	SoSimple *GetThisPointer()
	{
		return this; // 해당 객체의 포인터를 반환한다.
	}
};

int main(void)
{
	SoSimple sim1(100); // 객체 생성과 동시에 멤버변수 및 객체 자신의 주소값 출력 
	SoSimple *ptr1 = sim1.GetThisPointer(); // 해당 문장을 실행하는 객체의 포인터 반환
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple *ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}