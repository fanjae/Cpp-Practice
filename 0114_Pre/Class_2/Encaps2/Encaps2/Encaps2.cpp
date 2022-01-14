#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const
	{
		cout << "�๰�� ��~ ���ϴ�. " << "\n";
	}
};
class SneezeCap
{
public:
	void Take() const
	{
		cout << "��ä�Ⱑ �ܽ��ϴ�. " << "\n";
	}
};

class SnuffleCap
{
public:
	void Take() const
	{
		cout << "�ڰ� �� �ո��ϴ�." << "\n";
	}
};

class CONTAC600
{
	/* �����ִ� ������ �Լ��� �ϳ��� Ŭ���� �ȿ� ����ξ� ĸ��ȭ�� �����Ѵ�.
	������ ���� ĸ��ȭ�� ������ ������ �� �����ϰ� ĸ��ȭ�� �����ؾ� �Ѵ�. */
	private:
		SinivelCap sin;
		SneezeCap sne;
		SnuffleCap snu;

	public:
		void Take() const
		{
			sin.Take();
			sne.Take();
			snu.Take();
		}
};

class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600 &cap) const
	{
		cap.Take();
	}
};

int main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}
