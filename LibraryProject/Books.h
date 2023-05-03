//Made by Ryan Guay and Alanna Siebers
#pragma once
#ifndef books_h
#define books_h
#include "Inventory.h"
#include <string>
using namespace std;

class Books : public Inventory {
private:
	string author;
	int edition;
	string genre;
	string ISBN;
	double price;
public:

	Books();

	Books(string author, string title, int edition, string genre, string ISBN, double price, Publisher p);

	~Books();

	string GetAuthor();

	void SetAuthor(string a);

	string GetTitle();

	void SetTitle(string t);

	string GetPublisherEmail() { return publisher.getPublisherEmail(); }

	void SetPublisherEmail(string pe) {
		publisher.setPublisherEmail(pe);
	}

	string GetPublisherAddress() {
		return publisher.getPublisherAddress();
	}

	void SetPublisherAddress(string pa) {
		publisher.setPublisherAddress(pa);
	}

	string GetISBN();

	void SetISBN(string i);

	int GetEdition();

	void SetEdition(int e);

	double GetPrice();

	void SetPrice(double pr);

	string GetGenre() { return genre; };
	void SetGenre(string g) { genre = g; };

	Publisher GetPublisher() { return publisher; };
	void SetPublisher(Publisher p) { publisher = p; }

	void print();

};

#endif