#include <iostream>
int main()
{
	char ch;

	std::cout << "Ÿ�����Ͻø�, �ݺ� �����ϰڽ��ϴ�.\n";
	std::cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
		{
			std::cout << ch;	// ���� ������ �� ����
		}
		else
		{
			std::cout << ++ch;	// �� ���� ������ �� ����
		}
		std::cin.get(ch);
	}
	// ++ch ��� ch + 1�� ����ϸ� ��� �ɱ�?
	std::cout << "\n ȥ�������� �ؼ� �˼��մϴ�.\n";
	// std::cin.get();
	// std::cin.get();
	return 0;
}

/* ++ch�϶��� char�� Ÿ���̴�.
������, ch + 1�϶��� int�� Ÿ���̴�. (+1 �������� int������ ��ȯ�Ͽ� �����Ѵ�.)
�� ���÷� 'An'�� ������ 66111(B�� �ƽ�Ű�ڵ� ��, o�� �ƽ�Ű�ڵ� �� ���)
*/
