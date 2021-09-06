#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

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
	NameCard(const char *my_name, const char *my_company, const char *my_phone, int my_position) : position(my_position)
	{
		int name_len = strlen(my_name) + 1;
		int company_len = strlen(my_company) + 1;
		int phone_len = strlen(my_phone) + 1;

		name = new char[name_len];
		company = new char[company_len];
		phone = new char[phone_len];

		strcpy(name, my_name);
		strcpy(company, my_company);
		strcpy(phone, my_phone);
	}
	NameCard(const NameCard &Copy) : position(Copy.position)
	{
		int name_len = strlen(Copy.name) + 1;
		int company_len = strlen(Copy.company) + 1;
		int phone_len = strlen(Copy.phone) + 1;

		name = new char[name_len];
		company = new char[company_len];
		phone = new char[phone_len];

		strcpy(name, Copy.name);
		strcpy(company, Copy.company);
		strcpy(phone, Copy.phone);
	}
	void ShowNameCardInfo() const
	{
		cout << "�̸� : " << name << "\n";
		cout << "ȸ�� : " << company << "\n";
		cout << "����ó : " << phone << "\n";
		cout << "���� : "; COMP_POS::ShowPositionInfo(position);
	}
};
int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}
	