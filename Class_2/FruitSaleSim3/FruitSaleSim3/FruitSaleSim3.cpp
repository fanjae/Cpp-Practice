#include <iostream>
using namespace std;

class FruitSeller
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	// const ��������� �̴ϼȶ������� �̿��ϸ� �ʱ�ȭ�� �����ϴ�
	FruitSeller(int price, int num, int money) : APPLE_PRICE(price), numOfApples(num), myMoney(money)  
	{
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
	FruitBuyer(int money) : myMoney(money), numOfApples(0) // ��� �̴ϼȶ������� �̿��� �ʱ�ȭ
	{
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SalesApples(money);
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
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ " << "\n";
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ " << "\n";
	buyer.ShowBuyResult();
	return 0;
}