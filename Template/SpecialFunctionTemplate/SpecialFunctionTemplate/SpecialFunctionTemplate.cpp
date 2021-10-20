#include <iostream>
#include <cstring>

using namespace std;
template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <> // �Լ� ���ø��� Ư��ȭ
char * Max <char *>(char * a, char *b)
{
	cout << "char* Max <char *>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
} // char *�� �Լ��� �̿� ���� �����ϹǷ�, char *�� ���ø� �Լ��� �� ���¸� ����϶�. <char *> �κ��� ���� ���� ��.

template <>
const char* Max<const char *> (const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}  // const char *�� �Լ��� �̿� ���� �����ϹǷ�, char *�� ���ø� �Լ��� �� ���¸� ����϶�. <const char *> �κ��� ���� ���� ��.

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