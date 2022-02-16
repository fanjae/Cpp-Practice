#include <iostream>
#include <string>
using namespace std;
int function_call_count = 0;
void print(const char *data);
void print(const char *data, int value);
int main(void)
{
	const char data[100] = { "Username is FanJae." };
	print(data);
	print(data);
	print(data, 1);
}
void print(const char *data)
{
	cout << data << endl;
	function_call_count++;
}

void print(const char *data, int value)
{
	if (value == 0)
	{
		return;
	}
	for (int i = 1; i <= function_call_count; i++)
	{
		cout << data << endl;
	}
	function_call_count++;
}
