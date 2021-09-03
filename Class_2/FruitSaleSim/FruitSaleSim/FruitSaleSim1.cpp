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
			cout << "사과의 구매를 목적으로 0보다 작은 수를 전달할 수 없습니다." << "\n" << "\n";
			return 0;
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const 
	{
		cout << "남은 사과 : " << numOfApples << "\n";
		cout << "판매 수익 : " << myMoney << "\n" << "\n";
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
			cout << "사과의 구매를 목적으로 0보다 작은 수를 전달할 수 없습니다." << "\n" << "\n";
			return ;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		cout << "현재 잔액 : " << myMoney << "\n";
		cout << "사과 개수 : " << numOfApples << "\n" << "\n";
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

	cout << "과일 판매자의 현황 " << "\n";
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황 " << "\n";
	buyer.ShowBuyResult();
	return 0;
}