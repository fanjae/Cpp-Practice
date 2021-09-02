#include <iostream>

using namespace std;

class FruitSeller
{
	private:
		int APPLE_PRICE;
		int numOfApples;
		int myMoney;
	public:
		void InitMembers(int price, int num, int money)
		{
			APPLE_PRICE = price;
			numOfApples = num;
			myMoney = money;
		}
		int SalesApples(int money)
		{
			int num = money / APPLE_PRICE;
			numOfApples -= num;
			myMoney += money;
			return num;	
		}
		void ShowSalesResult()
		{
			cout << "���� ��� : " << numOfApples << "\n";
			cout << "�Ǹ� ���� : " << myMoney << "\n" << "\n";
		}
};

class FruitBuyer
{
	private: // ���� �������� �����ڸ� ������ ��� private�� �ȴ�. 
		int myMoney;
		int numOfApples;
	public:
		void InitMembers(int money)
		{
			myMoney = money;
			numOfApples = 0;
		}
		void BuyApples(FruitSeller &seller, int money)
		{
			numOfApples += seller.SalesApples(money); // ���� ����κ��� ������ �󸶿� ����� �������� ȣ�� 
			myMoney -= money;	
		}
		void ShowBuyResult()
		{
			cout << "���� �ܾ� : " << myMoney << "\n";
			cout << "��� ���� : " << numOfApples << "\n" << "\n";
		}
};

int main(void)
{
	FruitSeller seller;
	FruitBuyer buyer;
	
	seller.InitMembers(1000, 20, 0);
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); // ���� ����
	
	cout << "���� �Ǹ����� ��Ȳ " << "\n";
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ " << "\n";
	buyer.ShowBuyResult();
	return 0;
}
	
	
		
