#include <iostream>
using namespace std;
int main()
{
	using namespace std;
	int chest = 42;		// 10�� ������ ���
	int waist = 0x42;	// 16�� ������ ���
	int inseam = 042;	// 8�� ������ ���

	cout << "�����ѷ� " << chest << "\n";
	cout << "�㸮�ѷ� " << waist << "\n";
	cout << "�νɱ��� " << inseam << "\n";
	return 0;
}

/* cout�� �����ϴ� dec,hex,oct �����ڸ� �����Ѵ�.
10������ ����Ʈ �����̴�. ������ ���´� ����ڰ� �װ��� �����ϱ� ������ �����Ѵ�. */