#pragma once
#ifndef books_h
#define books_h

#include <string>
using namespace std;

class books {
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
		return author;
	}
	void SetAuthor(string a) {
		author = a;
	}

	string GetTitle() const {
		return title;
	}
	void SetTitle(string t) {
		title = t;
	}

	string GetPupblisher() const {
		return publisher;
	}
	void SetPublisher(string p) {
		publisher = p;
	}

	string GetPupblisherEmail() const {
		return publisherEmail;
	}
	void SetPublisherEmail(string pe) {
		publisher = pe;
	}

	string GetPupblisherAddress() const {
		return publisherAddress;
	}
	void SetPublisherAddress(string pa) {
		publisherAddress = pa;
	}

	int GetISBN() const {
		return ISBN;
	}
	void SetISBN(int i) {
		ISBN = i;
	}

	int GetEdition() const {
		return edition;
	}
	void SetEdition(int e) {
		edition = e;
	}

	double GetPrice() const {
		return price;
	}
	void SetPrice(double pr) {
		price = pr;
	}
};

#endif books_h

