#include <iostream>
using namespace std;

class SinivelCap
{
	public:
		void Take() const
		{
			cout << "콧물이 싹~ 납니다. " << "\n";
		}
};
class SneezeCap
{
	public:
		void Take() const
		{
			cout << "재채기가 멎습니다. " << "\n";
		}
};

class SnuffleCap
{
	public:
		void Take() const
		{
			cout << "코가 뻥 뚫립니다." << "\n";
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

	// 문제점 : 하나로 묶어 두지 않음에 따라서 복용 과정이 매우 복잡하다.
	// Encaps2.cpp에서 이에 대한 캡슐화를 진행하여 간략하게 한 예제를 보인다.
	// CONTAC600이라는 캡슐이 위 3개의 객체를 멤버로 둠으로써 캡슐화를 진행한다.
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnuffleCap(ncap);
	return 0;
}
