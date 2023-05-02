#ifndef NEWSPAPERS_H
#define NEWSPAPERS_H

#include "Inventory.h"
#include <string>
using namespace std;

class Newspapers : public Inventory {
private:
	string title;
	string date;
	string frequency;
	string ISBN;
	double price = 0.0;
public:
	Newspapers() {};
	Newspapers(string t, string d, string f, string isbn, double p) : title(t), date(d), frequency(f), ISBN(isbn), price(p) {};
	~Newspapers() {};

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
	string getISBN() { return ISBN; }
	double getPrice() {
		return price;
	}
};



#endif
