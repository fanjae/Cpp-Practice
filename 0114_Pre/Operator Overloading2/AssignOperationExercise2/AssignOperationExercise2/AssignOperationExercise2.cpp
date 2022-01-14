#include <iostream>
#include <cstring>

#pragma warning (disable:4996)
using namespace std;

class Book
{
private:
	char *title;
	char *isbn;
	int price;

public:
	Book(const char * my_title, const char *my_isbn, int value) : price(value)
	{
		this->title = new char[strlen(my_title) + 1];
		this->isbn = new char[strlen(my_isbn) + 1];
		strcpy(this->title, my_title);
		strcpy(this->isbn, my_isbn);
	}
	Book(const Book& ref) : price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}

	Book& operator= (const Book& ref)
	{
		delete[]title;
		delete[]isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
	void ShowBookInfo()
	{
		cout << "제목 : " << title << "\n";
		cout << "ISBN : " << isbn << "\n";
		cout << "가격 : " << price << "\n";
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char *DRMKey;
public:
	EBook(const char *my_title,const char *my_isbn, int value, const char *key) : Book(my_title, my_isbn, value)
	{
		DRMKey = new char[strlen(key) + 1];
		strcpy(DRMKey, key);
	}
	EBook(const EBook &ref) : Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator= (const EBook& ref)
	{
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키 : " << DRMKey << "\n";
	}
	~EBook()
	{
		delete[]DRMKey;
	}
};

int main(void)
{
	EBook ebook1("좋은 C++ ebook","555-12345-890-1", 10000,"fdx9w0i8kiw");
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	cout << "\n";

	EBook ebook3("dumy", "dumy", 0,"dumy");
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();
	return 0;
}
