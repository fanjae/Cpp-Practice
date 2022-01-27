#include <iostream>
#include <cctype>
using namespace std;
int main(void)
{
	char ch;
	cin >> ch;
	while (ch != '@')
	{
		if (islower(ch))
		{
			cout << (char)toupper(ch);
		}
		else if (isupper(ch))
		{
			cout << (char)tolower(ch);
		}
		else
		{
			cout << ch;
		}
		cin >> ch;
	}
}
