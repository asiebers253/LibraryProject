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
	int ISBN;
	double price;
public:
	Periodicals();
	Periodicals(string title, string date, string frequency, int ISBN, double price);
	~Periodicals();

	void setTitle(string t);
	void setDate(string d);
	void setFrequency(string f);
	void setISBN(int ISBN);
	void setPrice(double price);

	string getTitle();
	string getDate();
	string getFrequency();
	int getISBN();
	double getPrice();
};

#endif
