#include <iostream>
#include <string>
int main()
{
	using namespace std;
	string word = "?ate";
	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	cout << "루프가 끝난 후에 단어는 " << word << "입니다.\n";
	return 0;
}