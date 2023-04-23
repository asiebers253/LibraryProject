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
	int ISBN;
	double price;
public:
	Newspapers();
	Newspapers(string title, string date, string frequency, int ISBN, double price);
	~Newspapers();

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
