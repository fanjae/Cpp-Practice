#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
	private:
		char Print_Data[100];
		
	public:
		void SetString(const char *str)
		{
			strcpy(Print_Data,str);	
		}
		void ShowString()
		{
			cout << Print_Data << "\n";
		}	
};

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();
	
	pnt.SetString("I love C++");
	pnt.ShowString();
}
