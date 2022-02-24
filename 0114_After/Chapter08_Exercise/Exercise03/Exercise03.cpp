#include <iostream>
#include <string>

using namespace std;

void function_upper(string &data);
int main(void)
{
	string data;
	while (1)
	{
		cout << "문자열을 입력하시오 (끝내려면 q) : ";
		getline(cin, data);

		if (data[0] == 'q')
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else
		{
			function_upper(data);
			cout << data << "\n";
		}
	}
}
void function_upper(string &data)
{
	int str_size = data.size();
	for (int i = 0; i < str_size; i++)
	{
		data[i] = toupper(data[i]);
	}
}