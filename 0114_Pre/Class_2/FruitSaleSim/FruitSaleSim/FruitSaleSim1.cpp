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
	int SaleApples(int money)
	{
		if (money < 0)
		{
			cout << "����� ���Ÿ� �������� 0���� ���� ���� ������ �� �����ϴ�." << "\n" << "\n";
			return 0;
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const 
	{
		cout << "���� ��� : " << numOfApples << "\n";
		cout << "�Ǹ� ���� : " << myMoney << "\n" << "\n";
	}
};

class FruitBuyer
{
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
		if (money < 0)
		{
			cout << "����� ���Ÿ� �������� 0���� ���� ���� ������ �� �����ϴ�." << "\n" << "\n";
			return ;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ� : " << myMoney << "\n";
		cout << "��� ���� : " << numOfApples << "\n" << "\n";
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	buyer.BuyApples(seller, -1);

	cout << "���� �Ǹ����� ��Ȳ " << "\n";
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ " << "\n";
	buyer.ShowBuyResult();
	return 0;
}