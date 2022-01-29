#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(void)
{
	cout << "단어들을 입력하시오  (끝내려면 q) : \n";
	string word;
	cin >> word;

	int vowels = 0;
	int non_vowels = 0;
	int not_alpha = 0;
	while (word != "q")
	{
		if (isalpha(word[0]))
		{
			switch (word[0])
			{
				case 'A':
				case 'a':
					vowels++;
					break;
				case 'E':
				case 'e':
					vowels++;
					break;
				case 'I':
				case 'i':
					vowels++;
					break;
				case 'O':
				case 'o':
					vowels++;
					break;
				case 'U':
				case 'u':
					vowels++;
					break;
				default:
					non_vowels++;
			}
		}
		else
		{
			not_alpha++;
		}
		cin >> word;
	}
	cout << "모음으로 시작하는 단어 수 : " << vowels << endl;
	cout << "자음으로 시작하는 단어 수 : " << non_vowels << endl;
	cout << "기타 : " << not_alpha;
}
