#include <iostream>
using namespace std;

int main(void)
{
	int num = 0x010203;
	char *ptr = reinterpret_cast<char *>(&num); 
	// int�� ������ ����Ʈ ���� ������ ���ؼ� int�� �����͸� char�� �����ͷ� ����ȯ�� �Ͽ���.
	// �����͸� ������� �ϴ�, �׸��� �����Ϳ� �������ִ� ��� ������ �� ��ȯ�� ����Ѵ�.
	// 

	for (int i = 0; i < sizeof(num); i++)
	{
		cout << static_cast<int>(*(ptr + i)) << endl;
		// ����Ʈ ���� �����͸� ���ڰ� �ƴ� ������ ���·� ����ϱ� ���ؼ�
		// char�� �����͸� int�� �����ͷ� ��ȯ�ϰ� �ִ�.
	}
	return 0;
}