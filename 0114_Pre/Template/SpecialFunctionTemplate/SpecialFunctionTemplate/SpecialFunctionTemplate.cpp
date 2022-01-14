#include <iostream>
#include <cstring>

using namespace std;
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <> // 함수 템플릿의 특수화
char * Max <char *>(char * a, char *b)
{
	cout << "char* Max <char *>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
} // char *형 함수는 이와 같이 제시하므로, char *형 템플릿 함수는 위 형태를 사용하라. <char *> 부분은 생략 가능 함.

template <>
const char* Max<const char *> (const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}  // const char *형 함수는 이와 같이 제시하므로, char *형 템플릿 함수는 위 형태를 사용하라. <const char *> 부분은 생략 가능 함.

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;
	return 0;
}