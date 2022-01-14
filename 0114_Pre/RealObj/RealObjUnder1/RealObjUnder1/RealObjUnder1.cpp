#include <iostream>
using namespace std;

// 객체의 멤버함수와 멤버변수가 어떠한 형태로 구성되는지 설명하기 위한
// 모델이 될 C++ 코드
class Data
{
private:
	int data;
public:
	Data(int num) : data(num)
	{

	}
	void ShowData()
	{
		cout << "Data : " << data << "\n";
	}
	void Add(int num)
	{
		data += num;
	}
};

int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	return 0;
}