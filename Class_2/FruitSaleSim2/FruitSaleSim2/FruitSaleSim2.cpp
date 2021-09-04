#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) // ���� ������� �ùķ��̼� ��ü ������ ������ ������� ����
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
	void ShowSalesResult() const
	{
		cout << "���� ��� : " << numOfApples << "\n";
		cout << "�Ǹ� ���� : " << myMoney << "\n" << "\n";
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money) // ���� ������� �ùķ��̼� ��ü ������ ������ ������� ����
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SalesApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ� : " << myMoney << "\n";
		cout << "��� ���� : " << numOfApples << "\n";
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ " << "\n";
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ " << "\n";
	buyer.ShowBuyResult();
	return 0;
}