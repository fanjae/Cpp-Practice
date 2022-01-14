#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA() : num(0) { }
	AAA& CreateInitObj(int n) const
	{
		AAA *ptr = new AAA(n);
		return *ptr;
	}
	void ShowNum() const
	{
		cout << num << "\n";
	}
private:
	AAA(int n) : num(n) { }
};

int main(void)
{
	AAA base; // public 积己磊肺 积己(0栏肺 檬扁拳)
	base.ShowNum();

	AAA &obj1 = base.CreateInitObj(3); // private 积己磊肺 积己
	obj1.ShowNum();

	AAA &obj2 = base.CreateInitObj(12); // private 积己磊肺 积己
	obj2.ShowNum();

	delete &obj1;
	delete &obj2;
	return 0;
}