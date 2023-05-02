#ifndef JOURNALS_H
#define JOURNALS_H

#include "Inventory.h"
#include <string>
using namespace std;

class Journals : public Inventory {
private:
	string author = "";
	string title = "";
	int edition = 0;
	string ISBN = "";
	double price = 0.0;
public:
	Journals() {};
	Journals(string author, string title, int edition, string ISBN, double price) {
		this->author = author;
		this->title = title;
		this->edition = edition;
		this->ISBN = ISBN;
		this->price = price;
	}
	//~Journals();

	string GetAuthor() { return author; }

	void SetAuthor(string a) { author = a; }

	string GetTitle() { return title; }

	void SetTitle(string t) { title = t; }

	string GetISBN() { return ISBN; }

	void SetISBN(string i) { ISBN = i; }

	int GetEdition() { return edition; }

	void SetEdition(int e) { edition = e; }

	double GetPrice() { return price; }

	void SetPrice(double pr) { price = pr; }
};

#endif
