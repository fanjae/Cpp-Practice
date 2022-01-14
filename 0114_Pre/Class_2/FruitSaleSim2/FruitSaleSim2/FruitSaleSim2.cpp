#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) // 기존 과일장수 시뮬레이션 객체 생성을 생성자 기반으로 변경
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
		cout << "남은 사과 : " << numOfApples << "\n";
		cout << "판매 수익 : " << myMoney << "\n" << "\n";
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money) // 기존 과일장수 시뮬레이션 객체 생성을 생성자 기반으로 변경
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
		cout << "현재 잔액 : " << myMoney << "\n";
		cout << "사과 개수 : " << numOfApples << "\n";
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황 " << "\n";
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황 " << "\n";
	buyer.ShowBuyResult();
	return 0;
}