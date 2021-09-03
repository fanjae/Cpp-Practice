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

class ColdPatient
{
	public:
		void TakeSinivelCap(const SinivelCap &cap) const
		{
			cap.Take();
		}
		void TakeSneezeCap(const SneezeCap &cap) const
		{
			cap.Take();
		}
		void TakeSnuffleCap(const SnuffleCap &cap) const
		{
			cap.Take();
		}
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;

	// ������ : �ϳ��� ���� ���� ������ ���� ���� ������ �ſ� �����ϴ�.
	// Encaps2.cpp���� �̿� ���� ĸ��ȭ�� �����Ͽ� �����ϰ� �� ������ ���δ�.
	// CONTAC600�̶�� ĸ���� �� 3���� ��ü�� ����� �����ν� ĸ��ȭ�� �����Ѵ�.
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}
