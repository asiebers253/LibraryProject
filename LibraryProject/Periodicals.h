#ifndef PERIODICALS_H
#define PERIODICALS_H

#include "Inventory.h"
#include <string>
using namespace std;

class Periodicals : public Inventory {
private:
	string title;
	string date;
	string frequency;
	string ISBN;
	double price = 0.0;
public:
	Periodicals() {};
	Periodicals(string title, string date, string frequency, string ISBN, double price) {
		this->title = title;
		this->date = date;
		this->frequency = frequency;
		this->ISBN = ISBN;
		this->price = price;
	
	};
	~Periodicals() {};

	void setTitle(string t) {
		title = t;
	}
	void setDate(string d) {
		date = d;
	}
	void setFrequency(string f) {
		frequency = f;
	}
	void setISBN(string ISBN) {
		this->ISBN = ISBN;
	}
	void setPrice(double p) {
		price = p;
	}

	string getTitle() {
		return title;
	}
	string getDate() {
		return date;
	}
	string getFrequency() {
		return frequency;
	}
	string getISBN() { return ISBN; };
	double getPrice() {
		return price;
	}
};

#endif
