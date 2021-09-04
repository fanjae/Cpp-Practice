#include <iostream>
using namespace std;

class FruitSeller
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	// const 멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다
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
	FruitBuyer(int money) : myMoney(money), numOfApples(0) // 멤버 이니셜라이저를 이용한 초기화
	{
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SalesApples(money);
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
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황 " << "\n";
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황 " << "\n";
	buyer.ShowBuyResult();
	return 0;
}