#pragma once
#ifndef books_h
#define books_h

#include <string>
using namespace std;

class Books {
private:
	string author;
	string title;
	string publisher;
	int edition;
	int ISBN;
	string publisherEmail;
	string publisherAddress;
	double price;
public:

	Books();

	Books(string author, string title, string publisher, int edition, int ISBN, string publisherEmail, string publisherAddress, double price);

	~Books();

	string GetAuthor() {}

	void SetAuthor(string a) {}

	string GetTitle() {}

	void SetTitle(string t) {}

	string GetPublisher() {}

	void SetPublisher(string p) {}

	string GetPublisherEmail() {}

	void SetPublisherEmail(string pe) {}

	string GetPublisherAddress() {}

	void SetPublisherAddress(string pa) {}

	int GetISBN() {}

	void SetISBN(int i) {}

	int GetEdition() {}

	void SetEdition(int e) {}

	double GetPrice() {}

	void SetPrice(double pr) {}


};

#endif

