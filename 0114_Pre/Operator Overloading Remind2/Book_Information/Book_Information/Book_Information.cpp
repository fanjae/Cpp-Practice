#include <iostream>

#pragma warning (disable:4996)
using namespace std;
class Book
{
private:
	char *title;
	char *isbn;
	int price;

public:
	Book(const char *my_title, const char *my_isbn, int my_price) : price(my_price)
	{
		int my_title_len = strlen(my_title) + 1;
		int my_isbn_len = strlen(my_isbn) + 1;

		title = new char[my_title_len];
		strcpy(title, my_title);

		isbn = new char[my_isbn_len];
		strcpy(isbn, my_isbn);

	}
	Book& operator=(const Book &ref)
	{
		delete[] title;
		delete[] isbn;

		int len = strlen(ref.title) + 1;
		title = new char[len];
		strcpy(title, ref.title);

		len = strlen(ref.isbn) + 1;
		isbn = new char[len];
		strcpy(isbn, ref.isbn);
		price = ref.price;

		return *this;
		
	}
	void showBookInfo() const
	{
		cout << "제목 : " << title << "\n";
		cout << "ISBN : " << isbn << "\n";
		cout << "가격 : " << price << "\n";
	}
};

class EBook : public Book
{
private:
	char *DRMKey;
public:
	EBook(const char *my_title, const char *my_isbn, int my_price, const char *my_DRMKey) : Book(my_title, my_isbn, my_price)
	{
		int my_DRMKey_len = strlen(my_DRMKey) + 1;
		DRMKey = new char[my_DRMKey_len];
		strcpy(DRMKey, my_DRMKey);
	}
	void showEBookInfo() const
	{
		showBookInfo();
		cout << "인증키 : " << DRMKey << "\n";
	}
	
	EBook& operator=(const EBook &ref)
	{
		Book::operator=(ref);

		delete[]DRMKey;
		int len = strlen(ref.DRMKey) + 1;

		DRMKey = new char[len];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	EBook Ebook("좋은 C++", "555-12345-890-0", 20000,"1234");
	Book book2 = book;
	EBook Ebook2 = Ebook;


	book2.showBookInfo();
	Ebook2.showEBookInfo();
}