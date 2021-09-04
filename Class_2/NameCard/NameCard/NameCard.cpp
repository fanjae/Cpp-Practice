#include <iostream>
#include <cstring>
using namespace std;

#pragma warning (disable:4996)
namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "���" << "\n";
			break;
		case SENIOR:
			cout << "����" << "\n";
			break;
		case ASSIST:
			cout << "�븮" << "\n";
			break;
		case MANAGER:
			cout << "����" << "\n";
			break;
		}
	}
}
class NameCard
{
private:
	char *name;
	char *company;
	char *phone;
	int position;

public:
	NameCard(const char *temp_name,const char *temp_company,const char *temp_phone,const int temp_position) : position(temp_position)
	{
		name = new char[strlen(temp_name) + 1];
		company = new char[strlen(temp_company) + 1];
		phone = new char[strlen(temp_phone) + 1];
		strcpy(name, temp_name);
		strcpy(company, temp_company);
		strcpy(phone, temp_phone);
	}
	void ShowNameCardInfo() const
	{
		cout << "�̸� : " << name << "\n";
		cout << "ȸ�� : " << company << "\n";
		cout << "��ȭ��ȣ : " << phone << "\n";
		cout << "���� : "; COMP_POS::ShowPositionInfo(position);
	}
	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}