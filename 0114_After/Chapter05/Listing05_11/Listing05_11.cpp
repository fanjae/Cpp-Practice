#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	char word[5] = "?ate";

	for (char ch = 'a'; strcmp(word, "mate"); ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}
	// strcmp(word,"mate") == 두 문자열이 같지 않으면 1, 같으면 0이 된다.

	cout << "루프가 끝난 후에 단어는 " << word << "입니다.\n";
	return 0;
}