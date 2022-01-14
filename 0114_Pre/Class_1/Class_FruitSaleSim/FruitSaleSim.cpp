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
			cout << "남은 사과 : " << numOfApples << "\n";
			cout << "판매 수익 : " << myMoney << "\n" << "\n";
		}
};

class FruitBuyer
{
	private: // 만약 접근제어 지시자를 생략할 경우 private이 된다. 
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
			numOfApples += seller.SalesApples(money); // 과일 장수로부터 과일을 얼마에 사오는 과정에서 호출 
			myMoney -= money;	
		}
		void ShowBuyResult()
		{
			cout << "현재 잔액 : " << myMoney << "\n";
			cout << "사과 개수 : " << numOfApples << "\n" << "\n";
		}
};

int main(void)
{
	FruitSeller seller;
	FruitBuyer buyer;
	
	seller.InitMembers(1000, 20, 0);
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); // 과일 구매
	
	cout << "과일 판매자의 현황 " << "\n";
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황 " << "\n";
	buyer.ShowBuyResult();
	return 0;
}
	
	
		
